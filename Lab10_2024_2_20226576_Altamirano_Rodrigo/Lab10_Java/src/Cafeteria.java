import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Cafeteria {
    private final List<Pais> paises;
    private final List<Alumno> participantes;
    private final Menu menu;
    private final Scanner archivo;
    
    public Cafeteria() {
        paises = new ArrayList<>();
        this.participantes=new ArrayList<>();
        this.menu=new Menu();
        archivo = new Scanner(System.in);
    }
    
    public Cafeteria(final String nombreArchivo) throws FileNotFoundException {
        archivo = new Scanner(new File(nombreArchivo));
        paises = new ArrayList<>();
        this.participantes=new ArrayList<>();
        this.menu=new Menu();
    }
    
    public void cargarPaises() {
        while (archivo.hasNext()) {
            char tipo = archivo.next().charAt(0);
            if (!(tipo == 'I' || tipo == 'N')) break;
            
            Pais pais = new Pais();
            pais.cargar(archivo);
            paises.add(pais);
        }
    }
    
    public void cargarParticipantes() {
        while (true){
            String tipoParticipante=this.archivo.next();
            if (tipoParticipante.equals("FIN")) break;
            Alumno alumno;
            if (tipoParticipante.charAt(0)=='R') alumno=new AlumnoRegular();
            else alumno=new AlumnoIntercambio();
            alumno.cargar(this.archivo);
            this.participantes.add(alumno);
        }
    }
    
    public void cargarMenu() {
        this.menu.cargarProductos(this.archivo);
    }
    
    public void imprimirPaises() {
        System.out.println("==================LISTADO DE PAISES===================");
        System.out.println("------------------------------------------------------");
        System.out.println(String.format("%-15s\t%-10s\t%-10s\t%-10s", "NOMBRE", "MONEDA", "TIPO-CAMBIO", "IDIOMA"));
        System.out.println("------------------------------------------------------");
        for (Pais pais : paises) {
            pais.imprimir();
        }
        System.out.println("======================================================");
        System.out.println();
    }
    
    public void imprimirParticipantes() {
        System.out.println("=======================================================LISTADO DE PARTICIPANTES"+
                "============================================================");
        System.out.println("-------------------------------------------------------------------------------"+
                "------------------------------------------------------------");
        System.out.printf("%-12s%-35s%-10s%-25s%-15s%-50s%s\n","CODIGO","NOMBRE","FACULTAD","ESPECIALIDAD",
                "PAIS","IDIOMAS","DURACION");
        System.out.println("-------------------------------------------------------------------------------"+
                "------------------------------------------------------------");
        for (Alumno alumno : this.participantes) alumno.imprimir();
        System.out.println("==============================================================================="+
                "============================================================");
    }
    
    public void imprimirMenuPredeterminado() {
        this.menu.imprimirMenu();
    }
    
    public void imprimirMenusPersonalizados() {
        for (Alumno alumno : this.participantes) {
            Pais paisOrigen=this.buscarPais(alumno.getPaisOrigen());
            this.menu.imprimirMenuPersonalizado(alumno,paisOrigen);
        }
    }
    
    private Pais buscarPais(String nombre) {
        for (Pais pais : paises) {
            if (pais.getNombre().equals(nombre)) {
                return pais;
            }
        }
        
        return paises.get(0);
    }
}