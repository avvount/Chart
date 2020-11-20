#include <iostream>
#include <vector>
#include <chrono>   
using namespace std;
using namespace chrono;


#define DEBUG 1
#ifdef DEBUG
#define TIMER(NAME) \
class Timing\
{\
public:\
	Timing(std::string&& str) :action(str) {}\
	~Timing()\
	{\
		auto duration = system_clock::now() - start;\
		cout << action << "ºÄÊ±"\
			<< double(duration.count()) * microseconds::period::num / microseconds::period::den\
			<< "ºÁÃë" << endl;\
	}\
private:\
	system_clock::time_point start = system_clock::now();\
	std::string action;\
}Timing(NAME)
#else
#define TIMER(...)
#endif // DEBUG
#define FUNCTION_TIMER TIMER(__FUNCTION__)

int ctrl_shift(std::vector<double> a, std::vector<double> b)
{
	double t = std::numeric_limits<double>::lowest();
	FUNCTION_TIMER;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] > b[i])
		{
			t = a[i];
			a[i] = b[i];
			b[i] = t;
		}
	}
	return 0;
}

int ctrl_transfer(std::vector<double> a, std::vector<double> b)
{
	double x = std::numeric_limits<double>::lowest();
	FUNCTION_TIMER;
	double y = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		x = a[i] > b[i] ? a[i] : b[i];
		y = a[i] < b[i] ? a[i] : b[i];
		b[i] = x;
		a[i] = y;
	}
	return 0;
}

void fff()
{
	FUNCTION_TIMER;
	std::vector<double> a, b;
	for (size_t i = 0; i < 9999999; i++)
	{
		a.push_back(rand() / double(RAND_MAX));
		b.push_back(rand() / double(RAND_MAX));
	}

	for (int i = 10 - 1; i >= 0; i--)
	{
		ctrl_shift(a, b);
		ctrl_transfer(a, b);
	}
	//getchar();
}

#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)
int main()
{
	debug_print("WTF, %d\n", 958);
	fff();
	return 0;
}