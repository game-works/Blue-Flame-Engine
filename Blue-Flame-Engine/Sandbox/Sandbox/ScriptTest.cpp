#include "ScriptTest.h"
#include <iostream>

ScriptTest::ScriptTest()
{
}

ScriptTest::~ScriptTest()
{
}

void ScriptTest::Start()
{
	std::cout << "This is the test Script. It is exceuting the Start function. " << std::endl;
}

void ScriptTest::Update()
{
	std::cout << "This is the test Script. It is exceuting the Update function. " << std::endl;
}