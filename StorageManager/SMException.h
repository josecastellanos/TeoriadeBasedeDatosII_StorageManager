/* 
 * File:   SMException.h
 * Author: administrador
 *
 * Created on 8 de agosto de 2011, 3:30
 */

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

