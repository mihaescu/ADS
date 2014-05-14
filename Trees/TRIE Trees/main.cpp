#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include <conio.h>
#include <iostream>

using namespace std;

#define NR 27                // the American alphabet(26 letters) plus blank.


typedef struct TrieNode{
	bool NotLeaf;            // indicates if the TrieNode struct is a leaf or an intern node
	TrieNode *pChildren[NR]; // a list of pointers corresponding to the used alphabet
	char word[20];           // the string stored in node
};


//function for creating a leaf node 
TrieNode *NewLeaf(char keyWord[20])
{
	TrieNode *node;
	int count;
       
	      //allocating the necessary memory
	node = (TrieNode *)malloc(sizeof(TrieNode));

	for(count = 0; count < 27; count++)             //the terminal nodes don't have children
	                      node->pChildren[count] = NULL;
	node->NotLeaf = false;      // the node is a leaf
    strcpy(node->word,keyWord); //store in the structure(node->word) the string
	
	return node;   
}

//function for creating a intern node 
TrieNode *NewIntern()
{
	TrieNode *node;
	int count;

	    //allocating the necessary memory
	node = (TrieNode *)malloc(sizeof(TrieNode));

	for(count = 0; count < 27; count++)    // initial the intern node don't have children
		                 node->pChildren[count] = NULL;
	node->NotLeaf = true;	  //it isn't a leaf
	node->word[0] = 0;      //so we store the null string in node

	return node;
}

//function performs a search in the TRIE when a string or key is passed.
void Find(TrieNode *trie, char keyWord[20])
{
	TrieNode *next, *index, *data;
	int count;
	
	next = trie;  //start searching from the trie root
	
	if(next == NULL)  //trie is empty
	{
		cout << "Word not found in trie !!!!" << endl ;
		exit(1);
	}
	else
		index = next;// index - the current node from trie

	count = 0; // start searching for the first letter of the word(index of letter in word  is 0)
	while((index->NotLeaf == true) && (count < strlen(keyWord)) && (index->pChildren[keyWord[count]-'a'] != NULL))
	{// .... go down with 1 level
		next  = index->pChildren[keyWord[count]-'a']; // the actual node goes down with 1 level in trie following the pChildren field
		                                              // corresponding to the actual letter from keyWord
		index = next;
		count ++ ;   //move right in word with 1 level (1 letter)
	}

	if(next == NULL)
		cout << "Word not found in trie !!!!" << endl;
	else
	{
		data = next;
		    //the string is in a leaf
		if(!strcmp(data->word,keyWord))
			cout << "Key exists --- Word found in trie !!!!" << endl;
		else//the string is in the blank pointer(prefix for others words stored in trie)
			if((data->pChildren[26]) && !strcmp(data->pChildren[26]->word,keyWord))
				cout << "Key exists --- Word found in trie !!!!" << endl ;
			else
				cout << "Word not found in trie !!!!" << endl ;
    }
}

//function for inserting a string into the trie 
TrieNode *Insert(TrieNode *trie, char keyWord[20])
{
	TrieNode *next, *index, *parent;
	TrieNode *new_leaf, *data, *new_index;
	TrieNode *oldChildren, *newWord, *intern;
	
	int inWordIndex, prefixLenght, lenght = strlen(keyWord);
	
	next = trie;
	if(next == NULL) // if trie empty
	{
		trie     =  NewIntern();        //create an empty trie
		new_leaf =  NewLeaf(keyWord);   // create a leaf in which we store the new word
		trie->pChildren[keyWord[0]-'a'] = new_leaf; //add the leaf into the trie in the corresponding position

		return trie;
	}
	else      // non empty trie ..start searching
		index = next;

	inWordIndex = 0;   //move down in trie while end of word isn't reached and the pChildren branch node doesn't leads to NULL
	while((inWordIndex < lenght) &&(index->NotLeaf == true)&&(index->pChildren[keyWord[inWordIndex]-'a'] != NULL))
	{      // .... go down with 1 level
		parent = next; //set as parent the actual node
		next   = index->pChildren[keyWord[inWordIndex]-'a']; // the actual node goes down with 1 level in trie following the pChildren field
		                                                     // corresponding to the actual letter from keyWord
		index  = next;

		inWordIndex++;  //move right in word with 1 level (1 letter)
	}


	// if pChildren branch node points to NULL(end of prefix is reached) and no word already inserted, simply insert the word 
	if((inWordIndex < lenght) && (index->pChildren[keyWord[inWordIndex]-'a'] == NULL) && (index->NotLeaf == true))
	{
		new_index = NewLeaf(keyWord);
		index->pChildren[keyWord[inWordIndex]-'a'] = new_index;

		return trie;
	}
	else
		data=next;


	if(!strcmp(data->word,keyWord))
		cout << "Word already exists in trie !!!" << endl;
	else
	{    // store in oldChildren the subtree that derived from the same prefix as keyWord
		oldChildren = parent->pChildren[keyWord[inWordIndex-1]-'a'];
		newWord = NewLeaf(keyWord);

		prefixLenght= strlen(keyWord);
		if(data->word[0] != '\0')
		  if(strlen(data->word) < prefixLenght)// determine the minimum lenght of words
			           prefixLenght = strlen(data->word);
	}

	bool createIntern = false; 
	// Build a new subtree while the word to be inserted and the item that was in the leaf node have the same letters or the end of one of them is reached.
	while((inWordIndex <= prefixLenght)&&(((data->word[0] != '\0' )&& (data->word[inWordIndex-1] == keyWord[inWordIndex-1])) || (data->word[0] == '\0')))
	{
		intern = NewIntern();//create a new intern node
		parent->pChildren[keyWord[inWordIndex-1]-'a'] = intern; //insert this node in the corresponding field in parent->pChildren(with respect to the letter index in array)
		parent->NotLeaf = true;
		parent = intern;  // move down in tree with 1 level
		inWordIndex++;   // move right in word with 1 letter
		
		createIntern  = true;
	}
	if(createIntern)
	        inWordIndex--;

	//if items have a common prefix 
	if((inWordIndex != prefixLenght) || ((inWordIndex == prefixLenght)&&(strlen(keyWord) == strlen(data->word))))
	{//store in leaves the item that was to be inserted and the item that was originally in the leaf node.
		parent->pChildren[data->word[inWordIndex]-'a'] = oldChildren;
		parent->pChildren[keyWord[inWordIndex]-'a']    = newWord;
	}
	else // one word (keyWord or an item that was originally in the leaf node) represents a prefix for the other(s) item(s)
		if(data->word[0] != '\0')//just a word that has as prefix the keyword or vice versa 
              // insert the items as information nodes corresponding to the pChildren fields of prefixLenght and blank character 
		  if(strlen(data->word) <= prefixLenght)
		{
			parent->pChildren[26] = oldChildren;
			parent->pChildren[keyWord[prefixLenght]-'a'] = newWord;
		}
		else
		{
			parent->pChildren[26] = newWord;
			parent->pChildren[data->word[prefixLenght]-'a'] = oldChildren;
		}
		else// Two or more words that have the same prefix
		{
			for (int count = 0 ; count < 27;count++)//copy the subtree 
			      parent->pChildren[count] = oldChildren->pChildren[count];
			parent->pChildren[26] = newWord;//newWord is the prefix(save in blank pointer)
		}

	return trie;
}

//function for displaying the words stored in the trie
void DisplayTrie(TrieNode *trie, int nivel)
{
	int count;
	
	if(trie)
	{       
		if (trie->NotLeaf != true) // if TrieNode is a leaf(a word is stored in)
		{   // display the string at his level
			for (count = 0; count <= nivel; count++)  
				                   cout << " ";
			cout << trie->word << endl;
		}
		 // display all the words stored through trie children
		for (count = 26; count >= 0; count--)
			    DisplayTrie(trie->pChildren[count], nivel + 4);
	}

}

int main()
{
	TrieNode *trie;
	char UserInputWord[20], cont_insert=' ';
	int option = 0;  //stores the user's input(the chosen option)

	trie = NULL;

label_menu:   
	while( option != 5)
	{
		//display menu
		cout << endl << "                    Menu: " << endl;  
		cout <<         "___________________________________________" << endl;
	    cout << "     1. Create tree\n     2. Insert node\n     3. Search for node\n     4. Display tree\n     5. Exit\n";
		
		//get user input
		cout << "\n\n\nInput choice: ";
		cin  >> option; 


		switch (option) 
		{
		case 1:    //Create tree
			  while(cont_insert != 'n')
			   {
				   // get user input string
				cout << endl << "Insert word :";
				cin  >> UserInputWord;
				
				trie  = Insert(trie,UserInputWord);

				cout << "\n Continue ? <y/n>";
				cont_insert = getch();
			   }	
		     
			  break;
		case 2:    //Insert node
			  cout << endl << "Insert word :";
			  cin  >> UserInputWord;

			  Insert(trie,UserInputWord);
		      
			  break;
		case 3:     //Search for node
			  cout << endl << "Searched word :";
			  cin  >> UserInputWord;

			  Find(trie,UserInputWord);
			
			  break;
		case 4:    //Display tree
			  DisplayTrie(trie,0);
			
			  break;
		case 5:    //Exit
			  break;
		default:
			   cout << "Choose from the displayed options (1-5) !!!";
			   goto label_menu;
	  }//end switch
	}//end while

 system("PAUSE");
 return 0;
}



