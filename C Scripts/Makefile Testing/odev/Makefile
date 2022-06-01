# derleyicinin değişkene atanması
CC = gcc

# header ve kütüphane dosyalarının dizininin değişkene atanması
CFLAGS = -Wall -I./include -L./lib

# kaynak dosya ve obje dosyalarının dizinlerinin değişkenlere atanması
SRCDIR = src
OBJDIR = obj

# src klasörü içindeki bütün c dosyalarının bir değişkene atanması
SRCS = $(wildcard $(SRCDIR)/*.c)

# src klasöründeki bütün c dosyalarının, uzantılarının .o ile değiştirilip
# obj dosyasına kaydedilmiş dosyaların değişkene atanması
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# test dosyası ve kütüphane birleştirilip çalıştırılabilir bir program
# dosyasının  elde edilmesi
program: test/test.c lib/libtests.a
	$(CC) $(CFLAGS) $< -o $@ -ltests

# objelerden kütüphane dosyasının oluşturulması ve lib adında klasör
# oluşturup bu klasörün içine atılması. @ işareti ile o komutun
# çıktısı gizlenir
lib/libtests.a: $(OBJS)
	@mkdir -p lib
	ar rcs lib/libtests.a $^
	ranlib lib/libtests.a 

# c dosyalarının derlenip obje dosyalarına dönüştürülmesi ve obj adında
# klasör oluşturup obje dosyalarının bu klasör içine atılması
$(OBJDIR)/%.o:$(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -c -o $@

# make clean komutu geldiğinde oluşturulan çalıştırılabilir programın,
# lib klasörünün ve obj klasörünün silinmesi
clean:
	rm -rf program lib $(OBJDIR)

# dizinde clean adında bir dosya veya klasör var ise komutun doğru
# çalışmasını sağlar
.PHONY: clean
