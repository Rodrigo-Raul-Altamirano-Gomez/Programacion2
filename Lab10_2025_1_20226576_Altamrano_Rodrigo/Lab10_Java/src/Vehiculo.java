import java.util.Scanner;

public class Vehiculo extends Registro {
    private String placa;
    private String marca;
    private String modelo;
    private int anhoFab;
    private String categoria;
    private Propietario propietario;

    public Vehiculo() {
        this.propietario=new Propietario();
    }

    @Override
    public void cargar(Scanner archivo) {
        this.marca=archivo.next();
        this.modelo=archivo.next();
        this.anhoFab=archivo.nextInt();
        this.categoria=archivo.next();
        this.propietario.setDni(archivo.nextInt());
    }

    @Override
    public void imprimir() {
        System.out.println("Placa: "+this.placa);
        System.out.println("Marca: "+this.marca);
        System.out.println("Modelo: "+this.modelo);
        System.out.println("Año de Fabricacion: "+this.anhoFab);
        System.out.println("Categoria: "+this.categoria);
    }

    @Override
    public Object clone() {
        Vehiculo vehiculoClon=new Vehiculo();
        vehiculoClon.placa=this.placa;
        vehiculoClon.marca=this.marca;
        vehiculoClon.modelo=this.modelo;
        vehiculoClon.anhoFab=this.anhoFab;
        vehiculoClon.categoria=this.categoria;
        vehiculoClon.propietario=this.getPropietario();
        return vehiculoClon;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getAnhoFab() {
        return anhoFab;
    }

    public void setAnhoFab(int anhoFab) {
        this.anhoFab = anhoFab;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public Propietario getPropietario() {
        return (Propietario) propietario.clone();
    }

    public void setPropietario(Propietario propietario) {
        this.propietario = (Propietario) propietario.clone();
    }
}
