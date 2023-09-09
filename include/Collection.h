class Collection {
public:
    virtual void add(int value) = 0;
    virtual void remove(int value) = 0;
    virtual bool contains() = 0;
    virtual int size() = 0;
};