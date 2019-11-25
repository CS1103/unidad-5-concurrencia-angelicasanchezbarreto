
class Nodo{
private:
    int data;
    Nodo *next;
public:
    Nodo(int new_data){
        data=new_data;
        next=NULL;
    }
    int getData(){
        return data;
    }
    void setData(int new_data){
        data=new_data;
    }

    Nodo* goNext(int i){
        while(i>=1){
            if(i==1){
                return next;
            }
            else{
                next->setNext(next->goNext(1));
            }
            i=i-1;
        }
    }

    void setNext(Nodo *new_next){
        next=new_next;
    }

};
