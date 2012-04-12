#include <stdio.h>
#include <math.h>
#define maze_length 7
#define maze_width 7

// Declaration of variables
int is_at_end;
int path[maze_length][maze_breadth][maze_length][maze_breadth];
int parent_of[maze_length][maze_breadth];

// Initialization of variables
void init(){
	int i,j,k,l;
	
	for(i=0;i<maze_length;i++){
	
		for(j=0;j<maze_width;j++){
		
			for(k=0;k<maze_length;k++){
			
				for(l=0;l<maze_width;l++){
					path[i][j][k][l] = 0;
				}
			}
		}
	}
}

// Moves to given destination from given source point
void moveto(int arg1,int arg2,int arg3,int arg4){ 
	
	if(arg1 == arg3){
	
		if(arg4>arg2){
			//move forward;
		}
		
		else{
			//turn back;
			//move forward;
		}
	}
	
	else if(arg2 == arg4){
	
		if(arg3>arg1){
			//turn left;
			//move forward;
		}
		
		else{
			//turn right;
			//move forward;
		}
	}
	
}

// Checks whether the node has paths to its children or not
int no_out_path_from(int arg1,int arg2){
	int child_x,child_y;
	int flag = 0;
	int turned_back = 0;
	
	child_x = arg1 + 1;
	child_y = arg2;
	
	if(child_x < maze_length && parent_of[arg1][arg2]!=10*child_x + child_y){
		// turn left
		// move forward
		if(!turned_back) flag++;
	}
	
	child_x = arg1 - 1;
	child_y = arg2;
	
	if(child_x > 0 && parent_of[arg1][arg2]!=10*child_x + child_y){
		// turn right
		// move forward
		if(!turned_back) flag++;
	}
	
	child_x = arg1;
	child_y = arg2 + 1;
	
	if(child_y < maze_width && parent_of[arg1][arg2]!=10*child_x + child_y){
		// move forward
		if(!turned_back) flag++;
	}
	
	child_x = arg1;
	child_y = arg2 - 1;
	
	if(child_y > 0 && parent_of[arg1][arg2]!=10*child_x + child_y){
		// turn back
		// move forward
		if(!turned_back) flag++;
	}
	
	if(flag>0) return 1;
	else return 0;
}

// Checks whether the children have outward paths or not
int no_child_with_outpath(int arg1,int arg2){
	int child_x,child_y;
	int flag = 0;
	
	child_x = arg1 + 1;
	child_y = arg2;
	
	if(child_x < maze_length && parent_of[arg1][arg2]!=10*child_x + child_y){
		// turn left
		// move forward
		if(path[arg1][arg2][child_x][child_y]!=2) flag++;
	}
	
	child_x = arg1 - 1;
	child_y = arg2;
	
	if(child_x > 0 && parent_of[arg1][arg2]!=10*child_x + child_y){
		// turn right
		// move forward
		if(path[arg1][arg2][child_x][child_y]!=2) flag++;
	}
	
	child_x = arg1;
	child_y = arg2 + 1;
	
	if(child_y < maze_width && parent_of[arg1][arg2]!=10*child_x + child_y){
		// move forward
		if(path[arg1][arg2][child_x][child_y]!=2) flag++;
	}
	
	child_x = arg1;
	child_y = arg2 - 1;
	
	if(child_y > 0 && parent_of[arg1][arg2]!=10*child_x + child_y){
		// turn back
		// move forward
		if(path[arg1][arg2][child_x][child_y]!=2) flag++;
	}
	
	if(flag>0) return 1;
	else return 0;
}

// Goto the parent of the given node
void goto_parent_of(int arg1,int arg2){
	int current_x,current_y;
	int parent_x,parent_y,parent;
	
	current_x = arg1;
	current_y = arg2;
	parent = parent_of[current_x][current_y];
	parent_x = parent/10;
	parent_y = parent%10;
	on_optimal_path[current_x][current_y] = 0;
	
	moveto(current_x,current_y,parent_x,parent_y);
}

// Go to one of the children at random
void goto_child_of(int arg1,int arg2){// Return an integer in this function to depict which child is the bot going to
	int current_x=arg1,current_y=arg2;
	int child_x,child_y,no_of_paths;
	int flag = 0,flagl = 0,flagr = 0,flags = 0,flagb = 0;
	int random_path_number;
	
	child_x = arg1 + 1;
	child_y = arg2;
	
	if(child_x < maze_length && parent_of[arg1][arg2]!=10*child_x + child_y && path[arg1][arg2][child_x][child_y]!=2){
		// turn left
		// move forward
		flag++;
		flagl++;
	}
	
	child_x = arg1 - 1;
	child_y = arg2;
	
	if(child_x > 0 && parent_of[arg1][arg2]!=10*child_x + child_y && path[arg1][arg2][child_x][child_y]!=2){
		// turn right
		// move forward
		flag++;
		flagr++;
	}
	
	child_x = arg1;
	child_y = arg2 + 1;
	
	if(child_y < maze_width && parent_of[arg1][arg2]!=10*child_x + child_y && path[arg1][arg2][child_x][child_y]!=2){
		// move forward
		flag++;
		flags++;
	}
	
	child_x = arg1;
	child_y = arg2 - 1;
	
	if(child_y > 0 && parent_of[arg1][arg2]!=10*child_x + child_y && path[arg1][arg2][child_x][child_y]==2){
		// turn back
		// move forward
		flag++;
		flagb++;
	}
	
	no_of_paths = flag;
	random_path_number = rand(flag);
}

// Exploring the maze
void tremaux_exploring(int arg1,int arg2){
	int current_x=arg1,current_y=arg2;
	int successor_x,successor_y,parent_x,parent_y;
	is_at_end = 0;
	init();
	
	if(!is_at_end){
		
		if(no_out_path_from(current_x,current_y) || no_child_with_outpath(current_x,current_y)){
			goto_parent_of(current_x,current_y);
			parent_x = parent_of[current_x][current_y]/10;
			parent_y = parent_of[current_x][current_y]%10;
			path[parent_x][parent_y][current_x][current_y]++;
			tremaux_exploring(parent_x,parent_y);
		}
		
		else{
			goto_child_of(current_x,current_y);
			successor_x = successor_value(current_x,current_y)/10;
			successor_y = successor_value(current_x,current_y)%10;
			path[current_x][current_y][successor_x][successor_y]++;
			tremaux_exploring(successor_x,successor_y);
		}
		
	}
}