class Collection {
public:
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual bool contains(int value) = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
};