import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Producto extends Registro {
    private String codigo;
    private List<Traduccion> nombres;
    private List<Traduccion> descripciones;
    double precio;
    int stock;

    public Producto() {
        this.nombres=new ArrayList<>();
        this.descripciones=new ArrayList<>();
    }

    @Override
    public void cargar(Scanner archivo) {
        this.codigo=archivo.next();
        while (!archivo.hasNextDouble()) {
            Traduccion traduccion=new Traduccion("");
            traduccion.leer(archivo);
            this.nombres.add(traduccion);
        }
        this.precio=archivo.nextDouble();
        while (!archivo.hasNextInt()) {
            Traduccion traduccion=new Traduccion("");
            traduccion.leer(archivo);
            this.descripciones.add(traduccion);
        }
        this.stock=archivo.nextInt();
    }

    @Override
    public void imprimir() {
        Pais peru=new Pais("Peru","PEN",1.00,"ES");
        Alumno alumno=new AlumnoRegular();
        this.imprimir(alumno,peru);
    }

    public String obtenerNombre(String idioma) {
        Traduccion traduccionClave=new Traduccion(idioma);
        int posNombre=this.nombres.indexOf(traduccionClave);
        return this.nombres.get(posNombre).getTexto();
    }

    public String obtenerDescripcion(String idioma) {
        Traduccion traduccionClave=new Traduccion(idioma);
        int posDescripcion=this.nombres.indexOf(traduccionClave);
        return this.descripciones.get(posDescripcion).getTexto();
    }

    public void imprimir(Alumno alumno,Pais pais) {
        double precio=alumno.calcularPrecio(this,pais.getTipoCambio());
        System.out.printf("%s: %s\n",this.codigo,this.obtenerNombre(pais.getIdioma()));
        System.out.println(this.obtenerDescripcion(pais.getIdioma()));
        System.out.printf("Precio: %-3s %.2f\n",pais.getMoneda(),precio);
        if (this.stock>=0) System.out.println("Disponible: Si");
        else System.out.println("Disponible: No");
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public List<Traduccion> getNombres() {
        return Collections.unmodifiableList(nombres);
    }

    public void setNombres(List<Traduccion> nombres) {
        if (nombres!=null) this.nombres = new ArrayList<>(nombres);
        else this.nombres=new ArrayList<>();
    }

    public List<Traduccion> getDescripciones() {
        return Collections.unmodifiableList(descripciones);
    }

    public void setDescripciones(List<Traduccion> descripciones) {
        if (descripciones!=null) this.descripciones = new ArrayList<>(descripciones);
        else this.descripciones=new ArrayList<>();
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }
}
