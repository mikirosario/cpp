/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:49:19 by miki              #+#    #+#             */
/*   Updated: 2021/10/26 07:50:01 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>

#define PRINT std::cout
#define NL std::endl

int main(int argc, char **argv)
{
	if (argc == 2 && std::string(argv[1]).compare("school") == 0)
		goto school_test;
	//Real Tests
	{
	PRINT << "MUTANT STACK FLOAT LIST AND INT VECTOR INSTANTIATION" << NL;
	MutantStack< float,std::list<float> > mstacklist;
	MutantStack< int,std::vector<int> > mstackvector;
	PRINT << "\tPost-Instantiation Sizes: " << NL
	<< "\t\tMutantStack List Size: " << mstacklist.size() << NL
	<< "\t\tMutantStack Vector Size: " << mstackvector.size() << NL

	<< NL
	<< "MUTANT STACK FLOAT LIST AND INT VECTOR POPULATION" << NL;
	mstacklist.push(6.9);
	mstacklist.push(8.7);
	mstacklist.push(10.2834);
	mstacklist.push(42.42);
	mstackvector.push(73);
	mstackvector.push(59);
	mstackvector.push(42);
	mstackvector.push(1739268);
	PRINT << "\tPost-Population Sizes: " << NL
	<< "\t\tMutantStack List Size: " << mstacklist.size() << NL
	<< "\t\tMutantStack Vector Size: " << mstackvector.size() << NL
	<< "\tTop Tests: " << NL
	<< "\t\tMutantStack List Top Test: " << mstacklist.top() << NL
	<< "\t\tMutantStack Vector Top Test: " << mstackvector.top() << NL

	<< NL
	<< "MUTANT STACK FLOAT LIST ITERATOR TEST" << NL;
	for (MutantStack< float,std::list<float> >::iterator it = mstacklist.begin(), end = mstacklist.end(); it != end; ++it)
		PRINT << '\t' << *it << NL;

	PRINT << NL
	<< "MUTANT STACK INT VECTOR ITERATOR TEST" << NL;
	for (MutantStack< int,std::vector<int> >::iterator it = mstackvector.begin(), end = mstackvector.end(); it != end; ++it)
		PRINT << '\t' << *it << NL;

	PRINT << NL
	<< "MUTANT STACK FLOAT LIST COPY CONSTRUCTION TEST" << NL;
	//Copy Construction
	MutantStack < float,std::list<float> >	mstacklist_cpy(mstacklist);
	//Copy Construction
	for (MutantStack< float,std::list<float> >::iterator it = mstacklist_cpy.begin(), end = mstacklist_cpy.end(); it != end; ++it)
		PRINT << '\t' << *it << NL;
	
	PRINT << NL
	<< "MUTANT STACK FLOAT LIST ASSIGNMENT AND DEEP COPY TEST" << NL
	<< "\tCopy Via Assignment" << NL;
	MutantStack < float,std::list<float> >	mstacklist_assigned_cpy;
	//Copy Via Assignment
	mstacklist_assigned_cpy = mstacklist_cpy;
	//Copy Via Assignment
	PRINT << "\tPopping Top Off Float List Copy" << NL;
	mstacklist_cpy.pop();
	PRINT << "\tPopping Top Off Assigned Copy Twice" << NL;
	mstacklist_assigned_cpy.pop();
	mstacklist_assigned_cpy.pop();
	PRINT << "\tOriginal MutantStack List: " << NL;
	for (MutantStack< float,std::list<float> >::iterator it = mstacklist.begin(), end = mstacklist.end(); it != end; ++it)
		PRINT << "\t\t" << *it << NL;
	PRINT << "\tCopy Constructed MutantStack List: " << NL;
	for (MutantStack< float,std::list<float> >::iterator it = mstacklist_cpy.begin(), end = mstacklist_cpy.end(); it != end; ++it)
		PRINT << "\t\t" << *it << NL;
	PRINT << "\tCopy Assigned MutantStack List: " << NL;
	for (MutantStack< float,std::list<float> >::iterator it = mstacklist_assigned_cpy.begin(), end = mstacklist_assigned_cpy.end(); it != end; ++it)
		PRINT << "\t\t" << *it << NL;
	return (0);
	}
	//Real Tests

	//Icky School Test
	school_test:
	{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl; //LIFO/FILO - último en entrar, primero en salir
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it; //WHY???!!! xD
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	}
	//Icky School Test
	return (0);
}
