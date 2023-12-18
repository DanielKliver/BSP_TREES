#include<iostream>

const int num_of_polygon = 5;

using namespace std;


typedef class BSP_Node
{
	public:
	int index;
	BSP_Node* back = NULL;
	BSP_Node* front = NULL;

}BSP_Node;

typedef class point
{
	public:
	int x;
	int y;
}point;

typedef class polygon
{
	public:
	point one;
	point two;

}polygon;

typedef class plane 
{
	public:
	polygon* list_of_polygons;

}plane;


typedef class BSP_Tree
{
	private:

	plane *BSP_Plane;
	BSP_Node *root;

	

	public:

	void add_node(plane *BSP_Plane, BSP_Node *root)
	{

	}

	BSP_Tree(plane *BSP_Plane)
	{
		BSP_Node *root;root = new BSP_Node;this->root = root;
		this->BSP_Plane = BSP_Plane;
		for(int i = 0; i<num_of_polygon; i++)
		{
			polygon *polygon_now = &BSP_Plane->list_of_polygons[i];
			if(i == 0)
			{
				root->index = i;
			}
			make_tree(BSP_Plane, root);
		}
		
	}
	~BSP_Tree()
	{

	}
	
}BSP_Tree;

int main()
{
	//массив полигонов 
	plane *plane1 = new plane; plane1->list_of_polygons = new polygon[num_of_polygon]
	{
		{{3, 12}, {10, 16}},
		{{10, 14}, {14, 9}},
		{{9, 3}, {15, 7}},
		{{15, 12}, {17, 17}},
		{{5, 3}, {5, 9}}
	};

	BSP_Tree tree1(plane1);

	delete [] plane1;
	return 0;
}
