#include "MyForm.h"

using namespace Project1;

[STAThreadAttribute]
int main() {
	Application::Run(gcnew MyForm());

	return 0;
}