Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the Dynamic Arrays Tutorial!
Prerequesites: Arrays

In the last tutorials, we made arrays that always had a fixed size:
int numbers[10], which will always be 10 elements large

With dynamic arrays, we can change the size, depending on the value of a variable:
int size = 10;
int* numbers = new int[size];

After an array is made, the size cannot change, but the size can be determined before
the array is made, depending on conditions. For example:

if(something)
{
	size = 5;
}
else
{
	size = 10;
}
int* numbers = new int[size];
