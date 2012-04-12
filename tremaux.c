#include <stdio.h>
#include <stdlib>
#include <math.h>
#define maze_length 7
#define maze_width 7

int is_at_end;
int path[maze_length][maze_breadth][maze_length][maze_breadth];

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


void trace(int arg1,int arg2,char arg3) {
	//get current vertices
	int current_X, current_Y;
	current_X = arg1;
	current_y = arg2;
	int i,j,k,l;
	for(i=0; i<maze_length;i++) {
		for(j=0;j<maze_breadth;j++) {
		}
	}		
}

void tremaux_solving(int arg1,int arg2,char arg3){
	int current_x,current_y;
	int ch;
	char direction;
	current_x = arg1;
	current_y = arg2;
	is_at_end = 0;
	init();
	//int no_line_ahead = 1;
	while(!is_at_end){
		
		ch = rand(3);
		if (end) {
			is_at_end = 1;
			//keep the bot at the start again
			//calling function to trace
			trace();
			break;
		}
		
		if (no_line_ahead() == 0) {
			if (if_intersection == 0  && if_half_intersection() == 0) { 
				//turn around;
				//go back to parent;
				if (direction == 'n') {
					path[current_x][current_y][current_x[current_y+1]++;
				}
				
				if (direction == 's') {
					path[current_x][current_y][current_x][current_y-1]++;
				}
				
				if (direction == 'e') {
					path[current_x][current_y][current_x+1][current_y]++;
				}
				
				if (direction == 'w') {
					path[current_x][current_y][current_x-1][current_y]++;
				}
				
			}
			
			else if (if_intersection == 1) {
				if (ch==2) {
					ch =rand(2);
				}
			}
			
			else if (if_half_intersection == -1) {
				if (ch==1 || ch==2) {
					ch==0;
				}
			}
			
			else if (if_half_intersection == 1) {
				if (ch==0 || ch==2) {
					ch==1;
				}
			}	
		}
		
		
		
		if (if_intersection() == 0 && if_half_intersection() == 0) {
			if (direction == 'n') {
				path[current_x][current_y][current_x[current_y+1]++;
			}
			
			if (direction == 's') {
				path[current_x][current_y][current_x][current_y-1]++;
			}
			
			if (direction == 'e') {
				path[current_x][current_y][current_x+1][current_y]++;
			}
			
			if (direction == 'w') {
				path[current_x][current_y][current_x-1][current_y]++;
			}
		}
		
		else if (ch == 0 && (if_intersection() == 1 || if_half_intersection() == 1)) {
			turn_bot('l');
			//call black_line to travel just 1 unit;
			
			if (direction == 'n') {
				path[current_x][current_y][current_x-1][current_y]++;
			}
			
			if (direction == 's') {
				path[current_x][current_y][current_x+1][current_y]++;
			}
			
			if (direction == 'e') {
				path[current_x][current_y][current_x][current_y+1]++;
			}
			
			if (direction == 'w') {
				path[current_x][current_y][current_x][current_y-1]++;
			}
			
		}
		
		else if (ch == 1 && (if_intersection() == 1 || if_half_intersection() == 1)) {
			turn_bot('r');
			//call black_line to travel just 1 unit;
			
			if (direction == 'n') {
				path[current_x][current_y][current_x+1][current_y]++;
			}
			
			if (direction == 's') {
				path[current_x][current_y][current_x-1][current_y]++;
			}
			
			if (direction == 'e') {
				path[current_x][current_y][current_x][current_y-1]++;
			}
			
			if (direction == 'w') {
				path[current_x][current_y][current_x][current_y+1]++;
			}
		
		}
		
		else if (ch == 2 && if_intersection() == 1 ) {
			//call black_line to go straight one unit;
			
			if (direction == 'n') {
				path[current_x][current_y][current_x[current_y+1]++;
			}
			
			if (direction == 's') {
				path[current_x][current_y][current_x][current_y-1]++;
			}
			
			if (direction == 'e') {
				path[current_x][current_y][current_x+1][current_y]++;
			}
			
			if (direction == 'w') {
				path[current_x][current_y][current_x-1][current_y]++;
			}
		
		}
	}
}