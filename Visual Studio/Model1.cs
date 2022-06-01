using System;
using System.ComponentModel.DataAnnotations.Schema;
using System.Data.Entity;
using System.Linq;

namespace ODEV5
{
    public partial class Model1 : DbContext
    {
        public Model1()
            : base("name=Model1")
        {
        }

        public virtual DbSet<tBolum> tBolums { get; set; }
        public virtual DbSet<tDer> tDers { get; set; }
        public virtual DbSet<tFakulte> tFakultes { get; set; }
        public virtual DbSet<tOgrenci> tOgrencis { get; set; }
        public virtual DbSet<tOgrenciDer> tOgrenciDers { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<tBolum>()
                .Property(e => e.bolumAd)
                .IsUnicode(false);

            modelBuilder.Entity<tDer>()
                .Property(e => e.dersAD)
                .IsUnicode(false);

            modelBuilder.Entity<tFakulte>()
                .Property(e => e.fakulteAd)
                .IsUnicode(false);

            modelBuilder.Entity<tOgrenci>()
                .Property(e => e.ogrenciAd)
                .IsUnicode(false);

            modelBuilder.Entity<tOgrenci>()
                .Property(e => e.ogrenciSoyad)
                .IsUnicode(false);

            modelBuilder.Entity<tOgrenciDer>()
                .Property(e => e.yil)
                .IsUnicode(false);

            modelBuilder.Entity<tOgrenciDer>()
                .Property(e => e.yariyil)
                .IsUnicode(false);
        }
    }
}
