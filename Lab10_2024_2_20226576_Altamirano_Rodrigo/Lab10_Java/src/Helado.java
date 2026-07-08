import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Helado extends Producto {
    private List<String> toppings;

    public Helado() {
        super();
        this.toppings=new ArrayList<>();
    }

    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        int cantidadToppings=archivo.nextInt();
        for (int i=0; i<cantidadToppings;i++) this.toppings.add(archivo.next());
    }

    @Override
    public void imprimir() {
        super.imprimir();
    }

    @Override
    public void imprimir(Alumno alumno, Pais pais) {
        super.imprimir(alumno, pais);
        StringBuilder toppings=new StringBuilder();
        for (String topping : this.toppings) {
            toppings.append(topping);
            toppings.append(" ");
        }
        System.out.printf("Toppings: %s\n",toppings);
    }

    public List<String> getToppings() {
        return Collections.unmodifiableList(toppings);
    }

    public void setToppings(List<String> toppings) {
        if (toppings!=null) this.toppings = new ArrayList<>(toppings);
        else this.toppings=new ArrayList<>();
    }
}
