/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:14:18 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/21 00:08:10 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../class/Utility/proto.hpp"

void	title(std::string str, std::string color, size_t n)
{
	std::cout << color;
	for (size_t i = 0; i < n; i++)
		std::cout << " ";
	for (size_t i = 0; i < str.size(); i++)
		std::cout << "-";

	std::cout << std::endl;
	for (size_t i = 0; i < n; i++)
		std::cout << " ";
	std::cout << str << std::endl;

	for (size_t i = 0; i < n; i++)
		std::cout << " ";
	for (size_t i = 0; i < str.size(); i++)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << DEFAU;

}

void	vector_print(PRE::vector<int> &vec)
{
	std::cout << "   size: " <<vec.size();
	std::cout << "   capacity: " << vec.capacity() << std::endl;
	std::cout << "   max capacity: "<< vec.max_size() << std::endl;
	std::cout << "   Content:";
	for (PRE::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << std::endl;
	std::cout << "   Is empty ? " << vec.empty() << std::endl;
}

void	vector_test(PRE::vector<int> &vec)
{
	std::cout << "size: " <<vec.size();
	std::cout << "   capacity: " << vec.capacity() << std::endl;

	vec.push_back(28);

	std::cout << "size: " <<vec.size();
	std::cout << "   capacity: " << vec.capacity() << std::endl;
}


bool	vector_main()
{
	
	title("VECTOR", RED__, 0);
	std::cout << CHECK << std::endl;

	// Constructor
	title("Constructor", CYAN_, 1);
	{
		// Default
		title("Default | first", PURPL, 3);
		PRE::vector<int> first;	// empty vector of ints
		vector_print(first);

		// Fill
		title("Fill | second", PURPL, 3);
  		PRE::vector<int> second (4,100);	// four ints with value 100
		vector_print(second);

		// Range
		title("Range | third", PURPL, 3);
  		PRE::vector<int> third (second.begin(),second.end());	// iterating through second
		vector_print(third);
		
		// Copy
		title("Copy | fourth", PURPL, 3);
  		PRE::vector<int> fourth (third);	// a copy of third
		vector_print(fourth);

		// From Arraym
		title("From Array | fifth", PURPL, 3);
		int myints[] = {16,2,77,29};
  		PRE::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
		vector_print(fifth);

		// Operator=
		title("Operator - first = fifth - fifth = four", PURPL, 3);
		first = fifth;
		vector_print(first);
		fifth = fourth;
		vector_print(fourth);
	}

	title("Iterators", CYAN_, 1);
	{
		title("Empty fill with Push_back", PURPL, 3);
		PRE::vector<int> myvector;
		PRE::vector<int>::iterator it1 = myvector.begin();
		PRE::vector<int>::iterator it2 = myvector.end();

		std::cout << "   empty: " << myvector.empty() << std::endl;
		if (it1 == it2)
			std::cout << "   it1 == it2";
		else
			std::cout << "   it1 != it2";

  		for (int i=1; i<=5; i++) myvector.push_back(i);

		it1 = myvector.begin();
		it2 = myvector.end();
		if (it1 == it2)
			std::cout << "   it1 == it2" << std::endl;
		else
			std::cout << "   it1 != it2" << std::endl;

		vector_print(myvector);

		title("Print with begin then with rbegin x rend", PURPL, 3);

		std::cout << "   " << std::endl;
		for(it1 = myvector.begin(); it1 != myvector.end(); it1++)
			std::cout << ' ' << *it1;
			
		std::cout << std::endl << "   " << std::endl;
		for(PRE::vector<int>::reverse_iterator it3 = myvector.rbegin(); it3 != myvector.rend(); it3++)
			std::cout << ' ' << *it3;

	}
	title("Resize x Reserve", CYAN_, 1);
	{
		PRE::vector<int> alpha(6,42);

		title("Resize", PURPL, 3);
		vector_print(alpha);
		alpha.resize(4, 28);// n < _size
		vector_print(alpha);
		alpha.resize(10, 8);// n > _size && n > _capacity
		vector_print(alpha);
		alpha.resize(16, 2);// n > _size && n > _capacity
		vector_print(alpha);
		alpha.resize(68, 3);// n > _size && n > _capacity
		vector_print(alpha);

		title("Reserve", PURPL, 3);
		alpha.reserve(42);// n < _capicity
		vector_print(alpha);
		alpha.reserve(70);// n > _capicity
		vector_print(alpha);
	}

	title("Element access", CYAN_, 1);
	{
		title("Operator[]", PURPL, 3);
		{
			PRE::vector<int> alpha;

			alpha.reserve(10);
			for (size_t i = 0; i < 6; i++)
				alpha[i] = i;
			vector_print(alpha);
			alpha[3] = 42;
			for (size_t i = 0; i < alpha.size(); i++)
				std::cout << "   vector[" << i << "] = " << alpha[i] << std::endl;
		}
		
		title("At", PURPL, 3);
		{
			PRE::vector<int> alpha;

			alpha.resize(6);
			for (size_t i = 0; i < alpha.size(); i++)
				alpha.at(i) = i;
			alpha.at(3) = 42;
			for (size_t i = 0; i < alpha.size(); i++)
				std::cout << "   vector.at(" << i << ") = " << alpha.at(i) << std::endl;
		}

		title("Front && Back", PURPL, 3);
		{
			PRE::vector<int> alpha(1, 42);
			vector_print(alpha);
			std::cout << "   front: " << alpha.front() << " back: " << alpha.back() << std::endl;
			alpha.push_back(-42);
			std::cout << "   alpha.push_back(-42)" << " front: " << alpha.front() << " back: " << alpha.back() << std::endl;
			alpha.push_back(28);
			std::cout << "   alpha.push_back(-8)" << " front: " << alpha.front() << " back: " << alpha.back() << std::endl;
		}
		title("data", PURPL, 3);
		{
			PRE::vector<int> myvector(5);
			int	*p = myvector.data();

			*p = 10;
			++p;
			*p = 20;
			p[2] = 100;
			std::cout << "myvector contains:";
			for (unsigned i=0; i<myvector.size(); ++i)
				std::cout << ' ' << myvector[i];
			std::cout << std::endl;;
		}

	}

	title("Modifier", CYAN_, 1);
	{
		PRE::vector<int> alpha(10);

		vector_print(alpha);
		title("Assign", PURPL, 3);
		alpha.assign(12, 1);
		vector_print(alpha);
		int myints[] = {42, 28, 0, -42, 56789};
		alpha.assign(myints, myints + 4);
		vector_print(alpha);

		title("Push_back", PURPL, 3);

		PRE::vector<int> beta(alpha);
		std::cout << "push_back: 1, 2, 3, 99" << std::endl;
		beta.push_back(1);
		beta.push_back(2);
		beta.push_back(3);
		beta.push_back(99);
		vector_print(beta);

		title("Pop_back", PURPL, 3);
		while (beta.size())
		{
			beta.pop_back();
			vector_print(beta);
		}

		title("Insert", PURPL, 3);

		PRE::vector<int>::iterator	it = alpha.begin();
		int tab [] = { 501,502,503 };

		vector_print(alpha);
		alpha.insert(it + 2, 8);
		vector_print(alpha);
		alpha.insert(it + 3, 5, 42);
		vector_print(alpha);
		alpha.insert(it + 7, 6, -42);
		vector_print(alpha);
		alpha.insert(alpha.begin() + 2 , tab, tab + 3);
		vector_print(alpha);

		title("Erase", PURPL, 3);
		alpha.erase(alpha.begin());
		vector_print(alpha);
		alpha.erase(alpha.begin() + 2);
		vector_print(alpha);
		alpha.erase(alpha.begin(), alpha.begin() + 4);
		vector_print(alpha);
		alpha.erase(alpha.begin() + 1, alpha.end());
		vector_print(alpha);

		title("Swap", PURPL, 3);

		PRE::vector<int>	v1(alpha);
		PRE::vector<int>	v2(5, 8);

		std::cout << "   v1 =" << std::endl;
		vector_print(v1);
		std::cout << "   v2 =" << std::endl;
		vector_print(v2);
		v1.swap(v2);
		std::cout << "   v1 =" << std::endl;
		vector_print(v1);
		std::cout << "   v2 =" << std::endl;
		vector_print(v2);
		
		title("Clear", PURPL, 3);
		vector_print(v1);
		v1.clear();
		vector_print(v1);

		title("Allocator", PURPL, 3);
		std::vector<int> v3;
		int * p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = v3.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) v3.get_allocator().construct(&p[i],i);

		std::cout << "   The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << std::endl;

		// destroy and deallocate:
		for (i=0; i<5; i++) v3.get_allocator().destroy(&p[i]);
		v3.get_allocator().deallocate(p,5);

	}

	title("Non-mermbers function overload", CYAN_, 1);
	{
		title("Swap", PURPL, 3);

		PRE::vector<int>	v1(4, 6);
		PRE::vector<int>	v2;

		for (size_t i = 0; i < 5; i++)
			v2.push_back(i);

		std::cout << "   v1 =" << std::endl;
		vector_print(v1);
		std::cout << "   v2 =" << std::endl;
		vector_print(v2);
		swap(v1, v2);
		std::cout << "   v1 =" << std::endl;
		vector_print(v1);
		std::cout << "   v2 =" << std::endl;
		vector_print(v2);

		title("Relationnal operator", PURPL, 3);

		PRE::vector<int> foo(3,100);   // three ints with a value of 100
		PRE::vector<int> bar(2,200);   // two ints with a value of 200

		vector_print(foo);
		vector_print(bar);
		std::cout << "   foo == bar: ";
		if (foo ==bar)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
		
		std::cout << "   foo != bar: ";
		if (foo != bar)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;

		 std::cout << "   foo < bar: ";
		if (foo < bar)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
		 std::cout << "   foo <= bar: ";
		if (foo <= bar)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;

		 std::cout << "   foo > bar: ";
		if (foo > bar)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
		 std::cout << "   foo >= bar: ";
		if (foo >= bar)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;

		 std::cout << "   foo == foo: ";
		if (foo == foo)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
		 std::cout << "   foo != foo: ";
		if (foo != foo)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;

		 std::cout << "   foo < foo: ";
		if (foo < foo)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
		 std::cout << "   foo <= foo: ";
		if (foo <= foo)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;

		 std::cout << "   foo > foo: ";
		if (foo > foo)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
		 std::cout << "   foo >= foo: ";
		if (foo >= foo)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
	}
	return (true);
}