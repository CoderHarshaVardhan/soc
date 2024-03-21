#include<stdio.h>
#include<stdlib.h>

struct Student{
    int roll;
    char name[50];
    char gender;
    char branch[3];
};

struct Student students[100];

int nos = 0;

void addStudent();
void deleteStudent();
void updateStudent();
void searchStudent();
void displayStudents();
void saveData();
void loadData();


void addStudent(){
    if(nos > 100){
        printf("\nCannot add more students......");
    }else{
        printf("\nEnter roll number: ");
        scanf("%d",&students[nos].roll);
        fflush(stdin);
        printf("Enter name: ");
        scanf("%[^\n]",students[nos].name);
        fflush(stdin);
        printf("Enter gender (M/F): ");
        scanf("%c",&students[nos].gender);
        printf("Enter Branch: ");
        scanf("%s",students[nos].branch);

        nos++;
        printf("\nStudent added Successfully......");
    }
}

int checkRoll(int r){
    int count=-1;
    for(int i=0;i<nos;i++){
        if(students[i].roll == r){
            count += i+1;
        }
    }
        return count;
}


void deleteStudent(){
    int r;
    int count=0;
    if(nos==0){
        printf("\n No student is present in the database.....");
    }else{
        printf("\nEnter roll number  to be deleted : ");
        scanf("%d",&r);
        int rol = checkRoll(r);

        
        if(rol==-1){
        	printf("\nStudent details not found...");
        }else{
        	for(int j=rol;j<nos-1;j++){
                students[j] = students[j+1];

            }
            printf("\nStudent  Deleted Successfully........\n");
            nos--;
		}
    }

}

void updateStudent(){
    int rol;
    printf("\nEnter roll number: ");
    scanf("%d",&rol);
    int r = checkRoll(rol);
    if(r==-1){
    	printf("\nStudent record not found...");
    }else{
        printf("\nEnter roll number: ");
        scanf("%d",&students[r].roll);
        fflush(stdin);
        printf("\nEnter name: ");
        scanf("%[^\n]",students[r].name);
        fflush(stdin);
        printf("\nEnter gender[M/F]: ");
        scanf("%c",&students[r].gender);
        printf("\nEnter branch: ");
        scanf("%s",students[r].branch);
        printf("\nThe student details updated successfully.....");
    }
}


void searchStudent(){
    int r;
    printf("\nEnter roll number: ");
	scanf("%d",&r);
    int rol = checkRoll(r);

    if(rol==-1){
    	printf("\nStudent record not found");
   }else{
        printf("\nStudent record found.....\n");
        printf("\nRoll number: %d",students[rol].roll);
        printf("\nName: %s",students[rol].name);
        printf("\nGender: %c",students[rol].gender);
        printf("\nBranch: %s",students[rol].branch);
    }

}


void displayStudents(){
    for(int i=0;i<nos;i++){
        printf("\n---------------------------------------------------\n");
        printf("\nRoll number: %d",students[i].roll);
         printf("\nName: %s",students[i].name);
         printf("\nGender: %c",students[i].gender);
         printf("\nBranch: %s",students[i].branch);
        printf("\n---------------------------------------------------\n");
    }
}

void saveData() {
    FILE *fp = fopen("Details.txt", "wb");
    if (fp == NULL) {
        printf("\nError opening file for writing.\n");
        return;
    }

    fwrite(&nos, sizeof(int), 1, fp);
    fwrite(students, sizeof(struct Student), nos, fp);

    fclose(fp);
    printf("\nData saved successfully.\n");
}

void loadData() {
    FILE *fp = fopen("Details.txt", "rb");
    if (fp == NULL) {
        printf("\nNo previous data found.\n");
        return;
    }

    fread(&nos, sizeof(int), 1, fp);
    fread(students, sizeof(struct Student), nos, fp);

    fclose(fp);
}


void main(){
    int option;
    while(1){
    	loadData();
        printf("\n---------------------------------------------------\n");
        printf("\nStudent management system\n");
        printf("\n1.Add a Student");
        printf("\n2.Search a Student");
        printf("\n3.Display all Students");
        printf("\n4.Delete a student");
        printf("\n5.Update a student");
        printf("\n6.Save Details");
        printf("\n7.exit");

        printf("\nEnter  your option: ");
        scanf("%d",&option);
        switch(option){
            case 1:
            addStudent();
            break;
            case 2:
            searchStudent();
            break;
            case 3:
            displayStudents();
            break;
            case 4:
            deleteStudent();
            break;
            case 5:
            updateStudent();
            break;
            case 6:
            saveData();
            break;
            case 7:
            exit(0);
            break;
            default:
            printf("\nInvalid option......");
            break;
        }
    }
}




