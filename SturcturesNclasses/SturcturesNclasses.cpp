

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


typedef enum State {
	ENABLED ,
	FOWARD ,
	BACKWARD ,
	STOP ,
	DISABLED 
};

typedef union Connection{
	int networkID;
	char networkName[4];
};

typedef struct IPAddr {
	unsigned char Addr_1st;
	unsigned char Addr_2nd;
	unsigned char Addr_3rd;
	unsigned char Addr_4th;
};

// Employee class
class Employee
{
public:
	// Constructor
	Employee(std::string name, int id)
	{
		m_name = name;
		m_id = id;
	}

	// Public accessors
	std::string get_name() { return m_name; }
	int get_id() { return m_id; }
protected:
	// Private data for employee
	// Can only be set through constructor
	std::string m_name;
	int m_id;
};

// Manager is a superclass of an employee
class Manager : public Employee
{
public:
	// Use base class constructor
	Manager(std::string name, int id) : Employee(name, id) {}

	// Special manager function to add subordinates
	void add_subordinate(Employee employee)
	{
		m_manages.push_back(employee);
	}

	// Special manager report
	void report()
	{
		std::cout << std::setw(30) << std::right << "Manager: " << std::setw(10) << std::left << " " << m_name << std::endl;
		std::cout << std::setw(30) << std::right << "ID: " << std::setw(10) << std::left << " " << m_id << std::endl;
		std::cout << std::endl;
		std::cout << std::setw(30) << std::right << "Manages:" << std::endl;
		std::cout << std::setw(30) << std::right << "========" << std::endl << std::endl;

		// Iterate all subordinates
		for (Employee e : m_manages)
		{
			std::cout << std::setw(30) << std::right << e.get_name() << std::setw(10) << std::left << " " << e.get_id() << std::endl;
		}
	}
private:
	// Private data for manager
	std::vector<Employee> m_manages;
};

// Template 
template <typename T, int N>
class Array
{
public:
	T m_array[N];
	int get_size() { return N; }
};






void movement(enum State state) {
	switch (state) {
	case ENABLED:
		std::cout << "Engine started" << std::endl;
		break;
	case FOWARD:
		std::cout << "Car go forward" << std::endl;
		break;
	case BACKWARD:
		std::cout << "Car go backward" << std::endl;
		break;
	case STOP:
		std::cout << "Car stropped" << std::endl;
		break;
	case DISABLED:
		std::cout << "Engine is off" << std::endl;
		break;
	default:
		std::cout << "ERROR" << std::endl;
		break;
	}
}

int main()
{
	State state = STOP;
	state = FOWARD;
	movement(state);
	state = BACKWARD;
	movement(state);

	Connection net;
	net.networkID = 443;
	std::cout << "Network ID: " << net.networkID << std::endl;
	net.networkName[0] = 'T';
	net.networkName[1] = 'C';
	net.networkName[2] = 'P';
	net.networkName[3] = '\0';
	std::cout << "Network Name: " << net.networkName << std::endl;

	IPAddr ip;
	ip.Addr_1st = 172;
	ip.Addr_2nd = 16;
	ip.Addr_3rd = 1;
	ip.Addr_4th = 205;
	std::cout << "IP Address: " << (int)ip.Addr_1st << "." << (int)ip.Addr_2nd << "." << (int)ip.Addr_3rd << "." << (int)ip.Addr_4th << std::endl;

	// Employees
	Employee linda = Employee("Linda Shmer", 5689);
	Employee carol = Employee("Carol Cannavan", 9823);
	Employee mark = Employee("Mark Williamsonsford", 4789);

	// Manager
	Manager dave = Manager("Dave Field", 7589);

	// Setup data
	dave.add_subordinate(linda);
	dave.add_subordinate(carol);
	dave.add_subordinate(mark);

	// Provide report
	dave.report();


	std::cout << "Template" << std::endl;
    std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl;

	Array<std::string, 5> names;
	names.m_array[0] = "Linda";
	names.m_array[1] = "Carol";
	names.m_array[2] = "Mark";
	names.m_array[3] = "Dave";
	names.m_array[4] = "John";
	std::cout << "Size of array: " << names.get_size() << std::endl;
	std::cout << std::setw(15) << std::left << std::setfill(' ') << "Names: " << std::endl;
	for (int i = 0; i < names.get_size(); i++) {
		std::cout << names.m_array[i] << " " << std::endl;
	}

	std::cout << std::endl;

}

