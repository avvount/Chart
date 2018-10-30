class Link
{
    friend class List;
public:
    Link(const char *str=NULL);
    void print(void);
    Link *get_next(void);
private:
    char item[20];
    Link *next;
};

class List
{
public:
    List();
    ~List();
    List &Append(const char *str=NULL);
    List &Insert(const char *str=NULL);
    List &Delete(void);
    List &Remove(void);
    List &Clear(void);
    void Print(void);
private:
    Link *first;
    Link *last;
};