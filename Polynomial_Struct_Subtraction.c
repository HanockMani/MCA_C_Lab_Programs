#include<stdio.h>

struct poly{
	int coeff;
	int expo;
};

int read(struct poly p[]){
	int i,n;
	printf("\nEnter the number of terms in the expression: ");
	scanf("%d",&n);
	printf("\nEnter a polynomial expression:\n------------------------");
	for(i=0;i<n;i++){
		printf("\nEnter term %d:\nCoefficient: ",i+1);
		scanf("%d",&p[i].coeff);
		printf("\nExponent: ");
		scanf("%d",&p[i].expo);
	}
	return n;
}

void sort(struct poly p[], int n){
	int i,j;
	struct poly temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(p[j].expo<p[j+1].expo){
			    temp=p[j];
			    p[j]=p[j+1];
			    p[j+1]=temp;
			}
		}
	}
}

void disp(struct poly p[], int n){
	int i;
	sort(p,n);
	printf("\nExponent is: ");
	for(i=0;i<n;i++){
		if(p[i].expo==0){
			if(p[i].coeff<0)
				printf(" - %d",-p[i].coeff);
			else if(p[i].coeff>0){
				if(i==0)
					printf("%d",p[i].coeff);
				else
					printf(" + %d",p[i].coeff);
			}
		}
		else if(p[i].expo>0){
			if(p[i].coeff<0)
				printf(" - %dx^%d",-p[i].coeff,p[i].expo);
			else if(p[i].coeff>0){
				if(i==0)
					printf("%dx^%d",p[i].coeff,p[i].expo);
				else
					printf(" + %dx^%d",p[i].coeff,p[i].expo);
				}
		}
		else{
			if(p[i].coeff<0)
				printf(" - %d/x^%d",-p[i].coeff,-p[i].expo);
			else if(p[i].coeff>0){
				if(i==0)
					printf("%d/x^%d",p[i].coeff,-p[i].expo);
				else
					printf(" + %d/x^%d",p[i].coeff,-p[i].expo);
			}
		}
	}
}

int subtract(struct poly p1[10], struct poly p2[10], struct poly p3[10], int n1, int n2){
	int i, j, k;
	for(i=0;i<n;i++){
		p2[i].coeff=-p2[i].coeff;
	}
	i=0; j=0; k=0;
	while (i < n1 && j < n2){
		if (p1[i].expo == p2[j].expo){
			p3[k].coeff = p1[i].coeff + p2[j].coeff;
			p3[k].expo = p1[i].expo;
			i++;
			j++;
			k++;
		}
		else if (p1[i].expo > p2[j].expo){
			p3[k].coeff = p1[i].coeff;
			p3[k].expo = p1[i].expo;
			i++;
			k++;
		}
		else{
			p3[k].coeff = p2[j].coeff;
			p3[k].expo = p2[j].expo;
			j++;
			k++;
		}
	}
	while (i < n1){
		p3[k].coeff = p1[i].coeff;
		p3[k].expo = p1[i].expo;
		i++;
		k++;
	}
	while (j < n2){
		p3[k].coeff = p2[j].coeff;
		p3[k].expo = p2[j].expo;
		j++;
		k++;
	}
	return (k);
}

int main(){
	struct poly p1[10], p2[10], p3[10];
	int n1, n2, n3;
	printf("\nEnter First Polynomial:");
	n1=read(p1);
	disp(p1,n1);
	printf("\nEnter Second Polynomial:");
	n2=read(p2);
	disp(p2,n2);
	printf("\nSubtracting first polynomial from second:");
    	n3=subtract(p1,p2,p3,n1,n2);
    	disp(p3,n3);
}