/*
 * File:   Template.h
 * Author: joc
 *
 * Created on 4 de agosto de 2011, 15:09
 */

#ifndef TEMPLATE_H
#define	TEMPLATE_H

class Template {
public:
    Template();
    virtual void escribir() = 0;
    virtual unsigned int getEspacioDisponible() = 0;
private:

};

#endif	/* TEMPLATE_H */
