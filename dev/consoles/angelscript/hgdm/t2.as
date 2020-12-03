void test_fn(HGDM_Angel_Runtime_Context& harc)
{
 hQVariant@ hqv = harc.selto("prop-gate-params").pval().read();
 hQDebug(hqv);
}

void main()
{
 HGDM_Angel_Runtime_Context@ harc = new_rt_context();
 test_fn(harc);
}


