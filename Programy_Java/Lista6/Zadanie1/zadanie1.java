//Piotr Bolek Lista 6 Zadanie 1

import java.io.*;

class List<T> implements Serializable{
	public List<T> next;
	public List<T> prev;
	public T val;
}

class Lista<T> implements Serializable{

    private static final long serialVersionUID = 1L;

	private int size = 0;
	private List<T> list = new List<T>();
	public void add_top(T element){
		if(size == 0){
			list = new List<T>();
			list.val = element;
			size++;
			return;
		}
		if(list.next == null){
			list.next = new List<T>();
			list.next.prev = list;
			list = list.next;
			list.val = element;
			size++;
			return;
		}
		else
			list = list.next;
	}
	
	public T delete_top(){
		T element = null;
		if(size == 0)
			throw new IllegalArgumentException();
		if(list.next == null && list.prev == null){
			element = list.val;
			list = null;
			size--;
			return element;
		}
		else if(list.next == null && list.prev != null){
			element = list.val;
			list = list.prev;
			list.next = null;
			size--;
			return element;
		}
		else{
			element = list.val;
			list = list.next;
		}
		return element;
	}
	
	public T delete_begin(){
		T element = null;
		if(size == 0)
			throw new IllegalArgumentException();
		if(list.prev == null && list.next == null){
			element = list.val;
			list = null;
			size--;
			return element;
		}
		else if(list.prev == null && list.next != null){
			element = list.val;
			list = list.next;
			list.prev = null;
			size--;
			return element;
		}
		else{
			element = list.val;
			list = list.prev;
		}	
		return element;
	}
	
	public void add_begin(T element){
		if(size == 0){
			list = new List<T>();
			list.val = element;
			size++;
			return;
		}
		if(list.prev == null){
			list.prev = new List<T>();
			list.prev.next = list;
			list = list.prev;
			list.val = element;
			size++;
			return;
		}
		else
			list = list.prev;
	}
}

public class zadanie1{
    public static void main(String[] args){
        Lista<Integer> list = new Lista<Integer>();
        list.add_top(10);
        list.add_top(15);
        list.add_top(20);

        FileOutputStream fout = null;
        ObjectOutputStream oos = null;

        FileInputStream fin = null;
        ObjectInputStream ois = null;
        
        try{
            fout = new FileOutputStream("address.bin");
            oos = new ObjectOutputStream(fout);
            oos.writeObject(list);

            System.out.println("Zapisano");
        } catch (Exception ex){
            ex.printStackTrace();
        } finally {
            if (fout != null){
                try{
                    fout.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        list.add_top(30);
        try{
            fin = new FileInputStream("address.bin");
            ois = new ObjectInputStream(fin);
            list = (Lista<Integer>) ois.readObject();

            System.out.println("Wczytano");
        } catch (Exception ex){
            ex.printStackTrace();
        } finally {
            if(fin != null){
                try{
                    fin.close();
                } catch(IOException e){
                    e.printStackTrace();
                }
            }
        }

        while(list != null){
            try{
                System.out.println(list.delete_top());
            } catch(IllegalArgumentException e){
                System.out.println("Koniec listy");
                break;
            }
            
        }
    }
}