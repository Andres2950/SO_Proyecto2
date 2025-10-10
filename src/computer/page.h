#ifndef PAGE_H
#define PAGE_H

class Page {
    public:
        static int id_counter = 0;
        int id;
        int m_addr;
        int l_addr;
        int d_addr;
        int is_loaded;
        int load_t;
        int mark;

    Page(int m_addr, int l_addr, int d_addr){
        this.m_addr = m_addr;
        this.l_addr = l_addr;
        this.d_addr = d_addr;
        id_counter++;
        this.id = id_counter; 
    }
}

#endif
