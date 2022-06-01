namespace ODEV5
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("tOgrenci")]
    public partial class tOgrenci
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public tOgrenci()
        {
            tOgrenciDers = new HashSet<tOgrenciDer>();
        }

        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int ogrenciID { get; set; }

        [StringLength(25)]
        public string ogrenciAd { get; set; }

        [StringLength(25)]
        public string ogrenciSoyad { get; set; }

        public int? bolumID { get; set; }

        public virtual tBolum tBolum { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<tOgrenciDer> tOgrenciDers { get; set; }
    }
}
