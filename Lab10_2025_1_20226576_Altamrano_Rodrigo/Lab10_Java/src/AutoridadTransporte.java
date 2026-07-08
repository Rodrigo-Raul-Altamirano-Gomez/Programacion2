import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AutoridadTransporte {
    private final List<Propietario> propietarios;
    private final List<Vehiculo> vehiculos;
    private final List<Captura> capturas;
    private final List<RegistroInfraccion> regInfracciones;
    private final Scanner archivo;

    public AutoridadTransporte(String nombreArchivo) throws FileNotFoundException {
        this.propietarios=new ArrayList<>();
        this.vehiculos=new ArrayList<>();
        this.capturas=new ArrayList<>();
        this.regInfracciones=new ArrayList<>();
        this.archivo=new Scanner(new File(nombreArchivo));
    }

    public void cargarDatos() {
        while (this.archivo.hasNextInt()) {
            Propietario propietario=new Propietario();
            propietario.cargar(this.archivo);
            this.propietarios.add(propietario);
        }
        this.archivo.next();
        while (true) {
            String placa=this.archivo.next();
            if (placa.equals("FIN")) break;
            Vehiculo vehiculo=new Vehiculo();
            vehiculo.cargar(this.archivo);
            this.vehiculos.add(vehiculo);
        }
        while (this.archivo.hasNext()) {
            Captura captura=new Captura();
            captura.cargar(this.archivo);
            this.capturas.add(captura);
        }
    }

    public void procesarCapturas() {
        for (Captura captura : this.capturas) {
            int km=captura.getKm();
            double velocidad=captura.getVelocidad();
            Carril carril=captura.getCarril();
            Vehiculo vehiculo=this.buscarVehiculo(captura.getPlaca());
            if (!carril.vehiculoPermitido(vehiculo.getCategoria())) {
                RegistroInfraccion registroInfraccion=new RegistroInfraccion("G29",428,50,captura,vehiculo);
                this.regInfracciones.add(registroInfraccion);
            }
            if (!carril.velocidadPermitida(km,velocidad)) {
                RegistroInfraccion registroInfraccion=new RegistroInfraccion("M20",963,50,captura,vehiculo);
                this.regInfracciones.add(registroInfraccion);
            }
        }
    }

    private Vehiculo buscarVehiculo(String placa) {
        for (Vehiculo vehiculo : this.vehiculos) {
            if (placa.equals(vehiculo.getPlaca())) return vehiculo;
        }
        return null;
    }

    public void imprimirInfracciones() {
        System.out.printf("%35s\n","REGISTRO DE INFRACCION DE TRANSITO");
        for (RegistroInfraccion registroInfraccion : this.regInfracciones) {
            System.out.println("=========================================================");
            System.out.println("Codigo de Infraccion: "+registroInfraccion.getCodigoInfraccion());
            System.out.println("Monto de la Multa: "+registroInfraccion.getMonto());
            System.out.println("Puntos en Licencia: "+registroInfraccion.getPuntos());
            System.out.println("=========================================================");
            registroInfraccion.getVehiculo().imprimir();
            System.out.println("=========================================================");
            registroInfraccion.getCaptura().imprimir();
        }
    }
}
