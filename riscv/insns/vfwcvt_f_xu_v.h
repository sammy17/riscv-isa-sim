// vfwcvt.f.xu.v vd, vs2, vm
VI_VFP_CVT_SCALE
({
  auto vs2 = P.VU.elt<uint8_t>(rs2_num, i);
  P.VU.elt<float16_t>(rd_num, i, true) = ui32_to_f16(vs2);
},
{
  auto vs2 = P.VU.elt<uint16_t>(rs2_num, i);
  P.VU.elt<float32_t>(rd_num, i, true) = ui32_to_f32(vs2);
},
{
  auto vs2 = P.VU.elt<uint32_t>(rs2_num, i);
  P.VU.elt<float64_t>(rd_num, i, true) = ui32_to_f64(vs2);
},
{
  require(p->extension_enabled(EXT_ZFH));
},
{
  require(p->extension_enabled('F'));
},
{
  require(p->extension_enabled('D'));
},
true, (P.VU.vsew >= 8))
