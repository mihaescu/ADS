#include "MainWindow.h"
#include <string>
#include <cstdlib>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AlphaGUI::MainWindow mainWindow;
	Application::Run(%mainWindow);
}