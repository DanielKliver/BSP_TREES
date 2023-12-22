#include<iostream>


using namespace std;




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

		int index_of_polygon;

}polygon; 

typedef class BSP_Node
{
	public:
		int index;
		BSP_Node* splitter_polygon;
		BSP_Node* back = NULL;
		BSP_Node* front = NULL;
		polygon* list_of_polygons_node_front;
		polygon* list_of_polygons_node_back;

}BSP_Node;

//плоскость. содержит те же значения, что и полигон, но имеет направление нормали
typedef class plane
{
	public:
		point one;
		point two;

		int index_of_polygon;
		//направление нормали
		int normal_direction_sign;
		int normal_direction;
}plane;

class BSP_Tree
{
	private:

		BSP_Node *root = NULL;
		polygon *list_of_polygons = NULL;

	public:

		polygon* del_first_polygon(polygon *list_of_polygons, int num_of_polygon)
		{
			polygon *list_of_polygons_new = new polygon[num_of_polygon-1];

			//переменная для перебера новго массива
			int i = 0;
			//переменная для перебора старого массива
			int j = 1;
			while(i<num_of_polygon)
			{
				list_of_polygons_new[i] = list_of_polygons[j];
				i++; j++;
			}

			return list_of_polygons_new;
		}


		/*
		   void add_node(polygon *list_of_polygons, BSP_Node *root)
		   {

		   }
		   */

		plane *get_normals_for_vectors(polygon* list_of_polygons, BSP_Node* root, int num_of_polygon)
		{
			plane *list_of_planes = new plane[num_of_polygon]
			{
				{{3, 12}, {10, 16}, 1, -1, -1},
					{{10, 14}, {14, 9}, 2, -1, -1},
					{{9, 3}, {15, 7}, 3, -1, -1},
					{{15, 12}, {17, 17}, 4, -1, -1},
					{{5, 3}, {5, 9}, 5, -1, -1}

			};
			for(int i = 0; i<num_of_polygon; i++)
			{
				//0 указывает на смену знака для правильности определения фронт бэк в дальнейшем
				if(list_of_polygons->one.x<list_of_polygons->two.x)
				{
					if(list_of_polygons->one.y<list_of_polygons->two.y)
					{
						//При уравнении прямой с координатами сравниваемой точки >0 - внизу
						list_of_planes->normal_direction_sign = 1;
					}
					else if(list_of_polygons->one.y>list_of_polygons->two.y)
					{
						//<0 - сверху
						list_of_planes->normal_direction_sign = 0;
					}
					else
					{
						//y1 = y2
						list_of_planes->normal_direction_sign = 2;
					}
				}
				else if(list_of_polygons->one.x>list_of_polygons->two.x)
				{
					if(list_of_polygons->one.y>list_of_polygons->two.y)
					{
						//При уравнении прямой с координатами сравниваемой точки >0 - вверху
						list_of_planes->normal_direction_sign = 0;
					}
					else if(list_of_polygons->one.y<list_of_polygons->two.y)
					{
						//<0 - внизу
						list_of_planes->normal_direction_sign = 1;
					}
					else
					{
						//y1 = y2
						list_of_planes->normal_direction_sign = 2;
					}
				}
				else
				{

					//x1 = x2
					list_of_planes->normal_direction_sign = 3;

				}
				//выбираем непосредственно направление нормали 1 - вниз, 0 - вверх
				//векторам поочерёдно присваивается 0, 1, 0, 1
				if(i%2==1)
				{
					list_of_planes->normal_direction = 0;
				}
				else
				{
					list_of_planes->normal_direction = 1;
				}

			}
			return list_of_planes;
		}
		//                     список оставшихся полигонов     размер     разбивающая плоскость
		void check_front_back(polygon* list_of_polygons, int size_of_list, plane list_of_planes, BSP_Node root)
		{
			root.list_of_polygons_node_front = new polygon[size_of_list];
			root.list_of_polygons_node_back = new polygon[size_of_list];
			//беру текущую плоскость и строю уравнения в соответствии со знаками сравнеия и направлениями нормалей
			int size_front = 0;
			int size_back = 0;
			for(int i = 0; i< size_of_list; i++)
			{
				int karma = 0;

				if(list_of_polygons[i].one.x == list_of_planes.one.x && list_of_polygons[i].one.y == list_of_planes.one.y && list_of_polygons[i].two.x == list_of_planes.two.x && list_of_polygons[i].two.y == list_of_planes.two.y)
				{
					karma = 4;
				}
				if(list_of_planes.normal_direction_sign == 0 && list_of_planes.normal_direction == 0)
				{
					if(((list_of_polygons[i].one.x - list_of_planes.one.x)/(list_of_planes.two.x - list_of_planes.one.x))-((list_of_polygons[i].one.y - list_of_planes.one.y)/(list_of_planes.two.y - list_of_planes.one.y))<0)
					{
						karma++;
					}
					if(((list_of_polygons[i].two.x - list_of_planes.one.x)/(list_of_planes.two.x - list_of_planes.one.x))-((list_of_polygons[i].two.y - list_of_planes.one.y)/(list_of_planes.two.y - list_of_planes.one.y))<0)
					{
						karma++;
					}
				}
				if(list_of_planes.normal_direction_sign == 0 && list_of_planes.normal_direction == 1)
				{
					if(((list_of_polygons[i].one.x - list_of_planes.one.x)/(list_of_planes.two.x - list_of_planes.one.x))-((list_of_polygons[i].one.y - list_of_planes.one.y)/(list_of_planes.two.y - list_of_planes.one.y))>0)
					{
						karma++;
					}
					if(((list_of_polygons[i].two.x - list_of_planes.one.x)/(list_of_planes.two.x - list_of_planes.one.x))-((list_of_polygons[i].two.y - list_of_planes.one.y)/(list_of_planes.two.y - list_of_planes.one.y))>0)
					{
						karma++;
					}
				}
				if(list_of_planes.normal_direction_sign == 1 && list_of_planes.normal_direction == 0)
				{
					if(((list_of_polygons[i].one.x - list_of_planes.one.x)/(list_of_planes.two.x - list_of_planes.one.x))-((list_of_polygons[i].one.y - list_of_planes.one.y)/(list_of_planes.two.y - list_of_planes.one.y))<0)
					{
						karma++;
					}
					if(((list_of_polygons[i].two.x - list_of_planes.one.x)/(list_of_planes.two.x - list_of_planes.one.x))-((list_of_polygons[i].two.y - list_of_planes.one.y)/(list_of_planes.two.y - list_of_planes.one.y))<0)
					{
						karma++;
					}
				}
				if(list_of_planes.normal_direction_sign == 1 && list_of_planes.normal_direction == 1)
				{
					if(((list_of_polygons[i].one.x - list_of_planes.one.x)/(list_of_planes.two.x - list_of_planes.one.x))-((list_of_polygons[i].one.y - list_of_planes.one.y)/(list_of_planes.two.y - list_of_planes.one.y))>0)
					{
						karma++;
					}
					if(((list_of_polygons[i].two.x - list_of_planes.one.x)/(list_of_planes.two.x - list_of_planes.one.x))-((list_of_polygons[i].two.y - list_of_planes.one.y)/(list_of_planes.two.y - list_of_planes.one.y))>0)
					{
						karma++;
					}
				}
				//вертикаль
				if(list_of_planes.normal_direction_sign == 2 && list_of_planes.normal_direction == 0)
				{
					if(list_of_polygons[i].one.x>list_of_planes.one.x)
					{
						karma++;
					}
					if(list_of_polygons[i].two.x>list_of_planes.one.x)
					{
						karma++;
					}
				}
				if(list_of_planes.normal_direction_sign == 2 && list_of_planes.normal_direction == 1)
				{
					if(list_of_polygons[i].one.x<list_of_planes.one.x)
					{
						karma++;
					}
					if(list_of_polygons[i].two.x<list_of_planes.one.x)
					{
						karma++;
					}
				}
				//горизонталь
				if(list_of_planes.normal_direction_sign == 3 && list_of_planes.normal_direction == 0)
				{
					if(list_of_polygons[i].one.y<list_of_planes.one.y)
					{
						karma++;
					}
					if(list_of_polygons[i].two.y<list_of_planes.one.y)
					{
						karma++;
					}
				}
				if(list_of_planes.normal_direction_sign == 3 && list_of_planes.normal_direction == 1)
				{
					if(list_of_polygons[i].one.y>list_of_planes.one.y)
					{
						karma++;
					}
					if(list_of_polygons[i].two.y>list_of_planes.one.y)
					{
						karma++;
					}
				}



				if(karma == 2)
				{
					root.list_of_polygons_node_front[size_front] = list_of_polygons[i];
					size_front++;
				}
				if(karma == 0)
				{
					root.list_of_polygons_node_back[size_back] = list_of_polygons[i];
					size_back++;
				}

				if(karma > 2)
				{
					root.list_of_polygons_node_front[size_front] = list_of_polygons[i];
					size_front++;
					root.list_of_polygons_node_back[size_back] = list_of_polygons[i];
					size_back++;

				}
				
			}

		}



		void Build_BSP_Tree(polygon* list_of_polygons, BSP_Node* root, int num_of_polygon)
		{
			//НЕТ РЕКУРСИИ
			//Первый узел, корень
			if(list_of_polygons != NULL && root == NULL)
			{
				//если список полигоонов не пуст, 
				//корнем делаем первый попавшийся полигон
				root = new BSP_Node;
				root->index = list_of_polygons[0].index_of_polygon;
				plane *list_of_planes = get_normals_for_vectors(list_of_polygons, root, num_of_polygon);
				//функция удаления первого элемента листа полигонов
				this->list_of_polygons = del_first_polygon(list_of_polygons, num_of_polygon);
				//распределение оставшихся полигонов по front и back
				num_of_polygon--;

				check_front_back(list_of_polygons, num_of_polygon, list_of_planes[0], *root);
			}
			//НЕТ РЕКУРСИИ

			while(num_of_polygon!=0)
			{

			}


		}

		BSP_Tree(polygon *list_of_polygons, int num_of_polygon)
		{
			this->list_of_polygons = list_of_polygons;
			Build_BSP_Tree(list_of_polygons, root, num_of_polygon);
		}

		~BSP_Tree()
		{

		}

};

int main()
{
	//массив полигонов 
	int num_of_polygon = 5;
	polygon *list_of_polygons = new polygon[num_of_polygon]
	{
		{{3, 12}, {10, 16}, 1},
			{{10, 14}, {14, 9}, 2},
			{{9, 3}, {15, 7}, 3},
			{{15, 12}, {17, 17}, 4},
			{{5, 3}, {5, 9}, 5}

	};

	BSP_Tree tree1(list_of_polygons, num_of_polygon);

	delete [] list_of_polygons;
	return 0;
}
