import java.util.Scanner;

public class AlumnoRegular extends Alumno{
    private String especialidad;
    private String facultad;

    @Override
    public void imprimir() {
        super.imprimir();
        System.out.printf("%-10s%-25s%-15s%-50s%s\n",this.facultad,this.especialidad,"N/A","N/A","N/A");
    }

    @Override
    public void cargar(Scanner archivo) {
        super.cargar(archivo);
        this.especialidad=archivo.next();
        this.facultad=archivo.next();
    }

    @Override
    public String getPaisOrigen() {
        return "Peru";
    }

    @Override
    public double calcularPrecio(Producto producto,double tipoCambio) {
        return 0.97*producto.getPrecio();
    }

    public String getEspecialidad() {
        return especialidad;
    }

    public void setEspecialidad(String especialidad) {
        this.especialidad = especialidad;
    }

    public String getFacultad() {
        return facultad;
    }

    public void setFacultad(String facultad) {
        this.facultad = facultad;
    }
}
