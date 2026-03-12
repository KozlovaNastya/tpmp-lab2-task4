typedef struct {
    int year, month, day;
} Date;

typedef struct {
    char lastname[50], firstname[50], midname[50];
    char gender[10], nationality[30];
    int height, weight;
    Date birth;
    char phone[20];
    char address[200];
} Person;

bool FirstBiggerSecond(Date a, Date b);
