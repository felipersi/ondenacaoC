public interface Observer{
    void update(Observable o);
}

public class Obs_Server implements Observer{

    public void update(Observable o){
        ObservableData data = (ObservableData) o;
        data.getData();
    }
}

public class Obs_Software implements Observer{

    public void update(Observable o){
        ObservableData data = (ObservableData) o;
        data.getData();
    }
}

public class Obs_Network implements Observer{

    public void update(Observable o){
        ObservableData data = (ObservableData) o;
        data.getData();
    }
}

public abstract Subject{
    List observers = new ArrayList<>();

    public void add(Observer o){
        observers.add(o);
    }

    public void remove(Observer o){
        observers.remove(o);
    }

    public void notify(){
        Iterator it = observers.iterator();
        while(it.hasNext()){
            Observer o = (Observer)it.next();
            o.update(this);
        }
    }
}

public class SubjectData extends Subject{
    private Object myData;

    public void setData(Object myData){
        this.myData = myData;
        notify();
    }

    public Object getData(){
        return myData;
    }
}