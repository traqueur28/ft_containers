/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:43:15 by jgourlin          #+#    #+#             */
/*   Updated: 2022/08/22 00:41:31 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../class/Utility/proto.hpp"

void	stack_print(PRE::stack<int> &sta)
{
	std::cout << "   size: " <<sta.size();
  	std::cout << std::endl;
	if (sta.size() > 0)
		std::cout << "   Top element: " << sta.top() << std::endl;
	std::cout << "   Is empty ? " << sta.empty() << std::endl;
}

void	stack_print2(PRE::stack<int, PRE::vector<int> > &sta)
{
	std::cout << "   size: " <<sta.size();
  	std::cout << std::endl;
	if (sta.size() > 0)
		std::cout << "   Top element: " << sta.top() << std::endl;
	std::cout << "   Is empty ? " << sta.empty() << std::endl;
}

void	stack_main()
{
	title("STACK", RED__, 0);

	title("Constructor", CYAN_, 1);
	{
		title("first", PURPL, 3);
  		PRE::stack<int> first;
		stack_print(first);

		title("second | from vector", PURPL, 3);
  		PRE::vector<int>myvector(4, 42);

  		PRE::stack<int, PRE::vector<int> >second(myvector);
		stack_print2(second);

		title("third | from empty vector", PURPL, 3);
  		PRE::vector<int>v3;

  		PRE::stack<int, PRE::vector<int> >third(v3);
		stack_print2(third);

		title("fourth | from copy", PURPL, 3);
		PRE::stack<int, PRE::vector<int> >	fourth(second);
		stack_print2(fourth);

		title("third = fourth", PURPL, 3);
		third = fourth;
		stack_print2(third);
		stack_print2(fourth);
	}

	title("Element access x Capacity x Modifier", CYAN_, 1);
	{
		PRE::stack<int> alpha;
		stack_print(alpha);

		title("push(42)", PURPL, 3);
		alpha.push(42);
		stack_print(alpha);

		title("push(-42)", PURPL, 3);
		alpha.push(-42);
		stack_print(alpha);

		title("push(28)", PURPL, 3);
		alpha.push(28);
		stack_print(alpha);

		title("pop()", PURPL, 3);
		alpha.pop();
		stack_print(alpha);

		title("pop()", PURPL, 3);
		alpha.pop();
		stack_print(alpha);

		title("pop()", PURPL, 3);
		alpha.pop();
		stack_print(alpha);

		std::cout << std::endl << std::endl;

		PRE::stack<int, PRE::vector<int> > bravo;
		stack_print2(bravo);

		title("push(42)", PURPL, 3);
		bravo.push(42);
		stack_print2(bravo);

		title("push(-42)", PURPL, 3);
		bravo.push(-42);
		stack_print2(bravo);

		title("push(28)", PURPL, 3);
		bravo.push(28);
		stack_print2(bravo);

		title("pop()", PURPL, 3);
		bravo.pop();
		stack_print2(bravo);

		title("pop()", PURPL, 3);
		bravo.pop();
		stack_print2(bravo);

		title("pop()", PURPL, 3);
		bravo.pop();
		stack_print2(bravo);
	}

	{
		PRE::stack<int, PRE::vector<int> > foo;
		PRE::stack<int, PRE::vector<int> > bar;

		foo.push(42);
		bar.push(12);

		stack_print2(foo);
		stack_print2(bar);
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
	title("END STACK", RED__, 0);
}