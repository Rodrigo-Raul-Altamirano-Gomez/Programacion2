import java.util.Scanner;

public class Propietario extends Registro {
    private int dni;
    private String nombre;
    private String apellidos;
    private String direccion;

    @Override
    public void cargar(Scanner archivo) {
        this.dni=archivo.nextInt();
        this.nombre=archivo.next();
        this.apellidos=archivo.next();
        this.direccion=archivo.next();
    }

    @Override
    public void imprimir() {
        System.out.println("DNI: "+this.dni);
        System.out.println("Nombres: "+this.nombre);
        System.out.println("Apellidos: "+this.apellidos);
        System.out.println("Direccion: "+this.direccion);
    }

    @Override
    public Object clone() {
        Propietario propietarioClon=new Propietario();
        propietarioClon.dni=this.dni;
        propietarioClon.nombre=this.nombre;
        propietarioClon.apellidos=this.apellidos;
        propietarioClon.direccion=this.direccion;
        return propietarioClon;
    }

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getApellidos() {
        return apellidos;
    }

    public void setApellidos(String apellidos) {
        this.apellidos = apellidos;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }
}
