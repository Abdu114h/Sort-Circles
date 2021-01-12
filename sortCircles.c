#include <stdio.h>
#define SORT_BY_RADIUS 1
#define SORT_BY_CENTER 2

// structure representing a point on a plane
typedef struct
{
	double x;
	double y;
}COORDINATE;

// structure representing a circle on a plane
typedef struct
{
	COORDINATE center;
	double radius;
}CIRCLE;

void swapCircles(CIRCLE *pCircleA, CIRCLE *pCircleB);
int shouldCirleAPrecedeCircleB(CIRCLE A, CIRCLE B, int sortingMethod);
void sortCircles(CIRCLE *pCircles, int numCircles, int sortingMethod);
void printCircles(CIRCLE *pCircles, int numCircles);
void getCirclesFromUser(CIRCLE *pCircles, int numCircles);

int main()
{
	CIRCLE A[4];
	int sortingMethod;
	getCirclesFromUser(A, 4);
        printCircles(A, 4);
	printf("Do you want sort the circles by radius or by center?\n");
	printf("\t %d for by radius\n", SORT_BY_RADIUS);
        printf("\t %d for by center\n", SORT_BY_CENTER);
	scanf("%d", &sortingMethod);
	sortCircles(A, 4, sortingMethod);
	printCircles(A, 4);
	return 0;
}


void swapCircles(CIRCLE *pCircleA, CIRCLE *pCircleB)
{
	CIRCLE c;
	c=*pCircleA;
	*pCircleA=*pCircleB;
	*pCircleB=c;
}

/*******

The function below specifies the rule of sorting via the input parameter "sortingMethod",
which  takes value SORT_BY_RADIUS or SORT_BY_CENTER

*******/
int shouldCirleAPrecedeCircleB(CIRCLE A, CIRCLE B, int sortingMethod)
{
    int i;
	if(sortingMethod == 1)
    {
        if (A.radius>B.radius)
        {
            return 1;
        }
    }
    if(sortingMethod == 2)
    {
        int xA=A.center.x,yA=A.center.y,xB=B.center.x,yB=B.center.y;
        if ((xA^2+yA^2)>(xB^2+yB^2))
            {
                return 1;
            }
    }
	return 0;
}

int getindex(CIRCLE *pCircles, int numCircles, int sortingMethod)
{
    int i, index=0;

    for (i=1;i<numCircles;i++)
        {
            if(shouldCirleAPrecedeCircleB(pCircles[i], pCircles[index], sortingMethod)==1)
                {
                    index=i;
                }
            }
    return index;
}

void sortCircles(CIRCLE *pCircles, int numCircles, int sortingMethod)
{
	int i, k;
	for(i=0;i<numCircles-1;i++)
    {
        k= getindex(pCircles, numCircles-i, sortingMethod);
        swapCircles(pCircles+k, pCircles+numCircles-i-1);
    }

}

void printCircles(CIRCLE *pCircles, int numCircles)
{
    int i;

	for(i=0;i<numCircles;i++)
    {
        CIRCLE cir=pCircles[i];
        printf("\nCircle %d info:", i+1);
        printf("Radius: %.2lf\nCoordinates: (%.2lf,%.2lf)\n", cir.radius, cir.center.x, cir.center.y);

    }
}

void getCirclesFromUser(CIRCLE *pCircles, int numCircles)
{
    int i;

    for(int i=0; i<numCircles; i++){
        CIRCLE cir;
        COORDINATE cord;
        double x,y,r;

        printf("Enter the coordinates of Circle %d as XY\n", i+1);
        scanf("%lf %lf",&x,&y);

        printf("Enter the radius of circle %d\n", i+1);
        scanf("%lf",&r);

        cord.x = x;
        cord.y = y;
        cir.center = cord;
        cir.radius = r;
        pCircles[i] = cir;
    }
}
