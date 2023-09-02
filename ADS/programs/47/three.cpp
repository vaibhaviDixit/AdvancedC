/*
Every house in the colony has at most one pipe going into it and at most one pipe going out of it. Tanks and taps are to be installed in a manner such that
every house with one outgoing pipe but no incoming pipe gets a tank installed on its roof and every house with only an incoming pipe and no outgoing pipe
gets a tap.
Given two integers n and p denoting the number of houses and the number of pipes. The connections of pipe among the houses contain three
input values: a_i, b_i, d_i denoting the pipe of diameter d_i from house a_i to house b_i, find out the efficient solution for the network.
The output will contain the number of pairs of tanks and taps t installed in first line and the next t lines contain three integers: house number of tank,
house number of tap and the minimum diameter of pipe between them.

Input:  4 2
        1 2 60
        3 4 50
Output: 2
        1 2 60
        3 4 50

*/


#include <cstring> // For memset
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::memset;
using std::vector;
// number of houses and number of pipes
int number_of_houses, number_of_pipes;

// Array rd stores the ending vertex of pipe
int ending_vertex_of_pipes[1100];

// Array wd stores the value of diameters between two pipes
int diameter_between_two_pipes[1100];

// Array cd stores the starting end of pipe
int starting_vertex_of_pipes[1100];

// Vector a, b, c are used to store the final output
vector<int> a;
vector<int> b;
vector<int> c;

int ans;

int dfs(int w)
{
	if (starting_vertex_of_pipes[w] == 0)
		return w;
	if (diameter_between_two_pipes[w] < ans)
		ans = diameter_between_two_pipes[w];
	return dfs(starting_vertex_of_pipes[w]);
}

// Function performing calculations.
void solve(int arr[][3])
{
	for (int i = 0; i < number_of_pipes; ++i) {

		int house_1 = arr[i][0], house_2 = arr[i][1],
			pipe_diameter = arr[i][2];

		starting_vertex_of_pipes[house_1] = house_2;
		diameter_between_two_pipes[house_1] = pipe_diameter;
		ending_vertex_of_pipes[house_2] = house_1;
	}

	a.clear();
	b.clear();
	c.clear();

	for (int j = 1; j <= number_of_houses; ++j)

		/*If a pipe has no ending vertex
		but has starting vertex i.e is
		an outgoing pipe then we need
		to start DFS with this vertex.*/
		if (ending_vertex_of_pipes[j] == 0
			&& starting_vertex_of_pipes[j]) {
			ans = 1000000000;
			int w = dfs(j);

			// We put the details of component in final output array
			a.push_back(j);
			b.push_back(w);
			c.push_back(ans);
		}

	cout << a.size() << endl;
	for (int j = 0; j < a.size(); ++j)
		cout << a[j] << " " << b[j] << " " << c[j] << endl;
}

int main()
{
	number_of_houses = 9, number_of_pipes = 6;

	memset(ending_vertex_of_pipes, 0,
		sizeof(ending_vertex_of_pipes));
	memset(starting_vertex_of_pipes, 0,
		sizeof(starting_vertex_of_pipes));
	memset(diameter_between_two_pipes, 0,
		sizeof(diameter_between_two_pipes));

	int arr[][3]
		= { { 7, 4, 98 }, { 5, 9, 72 }, { 4, 6, 10 },
			{ 2, 8, 22 }, { 9, 7, 17 }, { 3, 1, 66 } };

	solve(arr);
	return 0;
}

/*
The program defines some global variables and arrays to store information about houses and pipes:

number_of_houses and number_of_pipes represent the total number of houses and pipes.
Arrays ending_vertex_of_pipes, diameter_between_two_pipes, and starting_vertex_of_pipes are used to store information about the pipes, their diameters, and connections between houses.
The dfs function performs a depth-first search starting from a given house (vertex) and returns the house where the search ends. It also keeps track of the minimum diameter encountered during the search.

The solve function takes a 2D array arr as input, where each row represents a pipe with three values: the first house, the second house, and the pipe's diameter. The function processes this input to find the minimum diameters required for each pipe network.

Inside the solve function:

The program processes each pipe and stores information about connections and diameters in the appropriate arrays.
It then initializes three vectors (a, b, and c) to store the final output. These vectors will contain information about the houses and the minimum diameters required for each pipe network.
Next, the program iterates through all houses and checks if a pipe has a starting vertex but no ending vertex. If so, it starts a depth-first search (dfs) to find the house where the network ends and calculates the minimum diameter encountered during the search.

The program appends the house, the ending house, and the minimum diameter to the respective vectors (a, b, and c) for each network.

Finally, the program prints the number of networks found and details about each network, including the starting house, ending house, and minimum diameter.

In the main function, sample values for number_of_houses, number_of_pipes, and the arr array (representing the pipes and their diameters) are provided. The solve function is called with this data to find and print the minimum diameters required for each pipe network.

*/
