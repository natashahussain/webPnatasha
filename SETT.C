void setunion(char *,char *,char *);
void setinter(char *,char *,char *);
void setdiff(char *,char *,char *);
void main()
{
  char s1[20],s2[20],s3[20];
  clrscr();

  printf("enter s1");
  scanf("%s",s1);
  printf("enter s1");
  scanf("%s",s2);
  setunion(s1,s2,s3);
  printf("\n the union set is %s",s3);
   setinter(s1,s2,s3);
  printf("\n the intersection set is %s",s3);
  setdiff(s1,s2,s3);
  printf("\n the difference set is %s",s3);
  getch();
  }
  void setunion(char *s1,char *s2,char *s3)
  {
   int i,l=strlen(s1);
   for(i=0;i<l;i++)
   {
     if(s1[i]=='0' && s2[i]=='0')
     s3[i]='0';
     else
     s3[i]='1';
     }
   s3[i]='\0';
   }
    void setinter(char *s1,char *s2,char *s3)
  {
   int i,l=strlen(s1);
   for(i=0;i<l;i++)
   {
     if(s1[i]=='1' && s2[i]=='1')
     s3[i]='1';
     else
     s3[i]='0';
     }
   s3[i]='\0';
   }
    void setdiff(char *s1,char *s2,char *s3)
  {
   int i,l=strlen(s1);
   for(i=0;i<l;i++)
   {
     if(s1[i]=='1' && s2[i]=='0')
     s3[i]='1';
     else
     s3[i]='0';
     }
   s3[i]='\0';
   }
