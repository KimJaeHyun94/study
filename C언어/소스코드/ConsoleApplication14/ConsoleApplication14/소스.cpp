#include <iostream>

class Number
{
private:
	int val;
public:
	Number(int val)
	{
		this->val = val;
	}
	int getValue() { return val; }

	Number& operator ++ ()
	{
		++val;
		return *this;
	}

	Number& operator -- ()
	{
		--val;
		return *this;
	}

	Number operator ++ (int)
	{
		Number copy(val);
		val++;
		return copy;
	}

	Number operator -- (int)
	{
		Number copy(val);
		val--;
		return copy;
	}
};

int main(int argc, char** argv)
{
	Number num(20);
	int intNum = 20;

	printf("%d\n", ++intNum);
	printf("%d\n\n", --intNum);

	printf("%d\n", intNum++);
	printf("%d\n\n", intNum--);

	printf("%d\n", (++num).getValue());
	printf("%d\n\n", (--num).getValue());

	printf("%d\n", num++.getValue());
	printf("%d\n\n", num--.getValue());

	return 0;
}