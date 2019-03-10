// MemoryUsage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Multiple choice test has several multiple choice questions. Each question can have only one correct 
answer. Additionally, timed multiple choice test can specify the time allowed for solving each question 
in the test.

The code below satisfies this specification, but the customer complained that the memory usage of 
the program constantly increases. Fix this problem.

https://www.quantstart.com/articles/C-Virtual-Destructors-How-to-Avoid-Memory-Leaks
From QuantStart Team

Inheritace also lends itself to virtual methods, where implementation is provided by any specific sublasses.
However, once an inheritance hierarchy is created, with memory allocation occuring at each stage in the
hierarchy, it is necessary to be very careful about how objects are destroyed so that any memory leaks are avoided.
In order to achieve this, we make use of virtual destructorl

*/
#include "pch.h"
#include <iostream>
#include <string>

class MultipleChoiceTest
{
public:
	MultipleChoiceTest(int questionsCount)
	{
		this->questionsCount = questionsCount;
		answers = new int[questionsCount];

		for (int i = 0; i < questionsCount; i++)
		{
			answers[i] = -1;
		}
	}

	virtual ~MultipleChoiceTest()
	{
		delete[] answers;
	}

	void setAnswer(int questionIndex, int answer)
	{
		answers[questionIndex] = answer;
	}

	int getAnswer(int questionIndex) const
	{
		return answers[questionIndex];
	}

protected:
	int questionsCount;

private:
	int* answers;
};

class TimedMultipleChoiceTest : public MultipleChoiceTest
{
public:
	TimedMultipleChoiceTest(int questionsCount)
		: MultipleChoiceTest(questionsCount)
	{
		times = new int[questionsCount];

		for (int i = 0; i < questionsCount; i++)
		{
			times[i] = 0;
		}
	}

	virtual ~TimedMultipleChoiceTest()
	{
		delete[] times;
	}

	void setTime(int questionIndex, int time)
	{
		times[questionIndex] = time;
	}

	int getTime(int questionIndex) const
	{
		return times[questionIndex];
	}

private:
	int* times;
};

#ifndef RunTests
void executeTest()
{
	MultipleChoiceTest test(5);
	for (int i = 0; i < 5; i++)
	{
		test.setAnswer(i, i);
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Question " << i + 1 << ", correct answer: " << test.getAnswer(i) << "\n";
	}
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Test: " << i + 1 << "\n";
		executeTest();
	}
}
#endif