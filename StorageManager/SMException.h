
#ifndef SMEXCEPTION_H
#define	SMEXCEPTION_H

#include <iostream>
#include <string>

using namespace std;

class SMException : public exception
{
public:
SMException(string m="exception!") : msg(m) {}
~SMException() throw() {}
const char* what() const throw() { return msg.c_str(); }

private:
string msg;
};

#endif	/* SMEXCEPTION_H */
