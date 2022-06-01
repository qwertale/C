namespace ODEV5
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    public partial class tOgrenciDer
    {
        [Key]
        [DatabaseGenerated(DatabaseGeneratedOption.None)]
        public int ogrenciDersID { get; set; }

        public int? ogrenciID { get; set; }

        public int? dersID { get; set; }

        [StringLength(20)]
        public string yil { get; set; }

        [StringLength(25)]
        public string yariyil { get; set; }

        public int? vize { get; set; }

        public int? final { get; set; }

        public virtual tDer tDer { get; set; }

        public virtual tOgrenci tOgrenci { get; set; }
    }
}
