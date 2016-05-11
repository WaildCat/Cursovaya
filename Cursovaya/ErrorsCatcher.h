#pragma once
class ErrorsCatcher
{
	
public:
	ErrorsCatcher();
	~ErrorsCatcher();
	void OutOfBounds();
	void ErrorInInput(int&);
	void ErrorInInput(string&, int&);
	void CorruptedFileData();
};

