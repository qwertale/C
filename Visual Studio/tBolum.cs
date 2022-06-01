namespace ODEV5
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("tBolum")]
    public partial class tBolum
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public tBolum()
        {
            tDers = new HashSet<tDer>();
            tOgrencis = new HashSet<tOgrenci>();
        }

        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int bolumID { get; set; }

        [StringLength(25)]
        public string bolumAd { get; set; }

        public int? fakulteID { get; set; }

        public virtual tFakulte tFakulte { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<tDer> tDers { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<tOgrenci> tOgrencis { get; set; }
    }
}
