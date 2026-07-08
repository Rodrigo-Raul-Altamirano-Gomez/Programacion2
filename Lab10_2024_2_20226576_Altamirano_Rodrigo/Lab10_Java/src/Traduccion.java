import java.util.Scanner;

class Traduccion {
    private String idioma;
    private String texto;

    public Traduccion(String idioma) {
        this.idioma=idioma;
    }

    public String getIdioma() {
        return idioma;
    }

    public String getTexto() {
        return texto;
    }
    
    public void setIdioma(String idioma) {
        this.idioma = idioma;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }

    public void leer(Scanner archivo) {
        this.idioma=archivo.next();
        this.texto=archivo.next();
    }

    @Override
    public boolean equals(final Object traduccion) {
        if (traduccion==null || this.getClass()!=traduccion.getClass()) return false;
        else return this.idioma.equals(((Traduccion) traduccion).idioma);
    }
}