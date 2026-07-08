import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class AlumnoIntercambio extends Alumno {
    private String paisOrigen;
    private List<String> idiomas;
    private int numeroDeSemestres;

    public AlumnoIntercambio() {
        idiomas=new ArrayList<>();
    }

    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        this.paisOrigen=archivo.next();
        while (!archivo.hasNextInt()) {
            String idioma=archivo.next();
            this.idiomas.add(idioma);
        }
        this.numeroDeSemestres=archivo.nextInt();
    }

    @Override
    public void imprimir() {
        StringBuilder idiomas= new StringBuilder("[");
        for (String idioma : this.idiomas) {
            idiomas.append(idioma);
            if (idioma!=this.idiomas.getLast()) idiomas.append(", ");
            else idiomas.append("]");
        }
        super.imprimir();
        System.out.printf("%-10s%-25s%-15s%-50s%d\n","N/A","N/A",this.paisOrigen,idiomas,this.numeroDeSemestres);
    }

    @Override
    public String getPaisOrigen() {
        return this.paisOrigen;
    }

    @Override
    public double calcularPrecio(Producto producto,double tipoCambio) {
        return 0.95*producto.getPrecio()*tipoCambio;
    }

    public void setPaisOrigen(String paisOrigen) {
        this.paisOrigen = paisOrigen;
    }

    public List<String> getIdiomas() {
        return Collections.unmodifiableList(idiomas);
    }

    public void setIdiomas(List<String> idiomas) {
        if (idiomas!=null) this.idiomas=new ArrayList<>(idiomas);
        else this.idiomas=new ArrayList<>();    
    }

    public int getNumeroDeSemestres() {
        return numeroDeSemestres;
    }

    public void setNumeroDeSemestres(int numeroDeSemestres) {
        this.numeroDeSemestres = numeroDeSemestres;
    }
}
