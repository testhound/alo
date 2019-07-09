#include "OctaveInstructions.h"
#include "OctaveFactory.h"

namespace Llir
{
  OctaveFactory::OctaveFactory() 
    : m_nullOperand(new OpndNull()),
      m_nullReg(new NullRegister()),
      m_nullSymbol(new NullSymbol()),
      m_nullType(new NullType()),
      m_numPseudoRegs(0),
      m_modFlags(LAST_MOD),
      m_essFlags(LAST_ESS),
      m_negatedEssFlags(LAST_ESS),
      m_mvhFlags(LAST_MVH),
      m_brslFlags(LAST_BRSL),
      m_cbranchFlags(LAST_CBRANCH),
      m_findFlag(shared_ptr<FindFlag>(new FindFlag)),
      m_cumeFlag(shared_ptr<CumeFlag>(new CumeFlag)),
      m_diFlag(shared_ptr<DIFlag>(new DIFlag)),
      m_signFlag(shared_ptr<SignFlag>(new SignFlag)),
      m_cdFlag(shared_ptr<CDFlag>(new CDFlag)),
      m_depbFlag(shared_ptr<DepbFlag>(new DepbFlag)),
      m_sxFlag(shared_ptr<SXFlag>(new SXFlag)),
      m_abcFlags(LAST_ABC),
      m_abcCompareFlags(LAST_ABC_COMPARE),
      m_tssFlags(LAST_TSS),
      m_linkFlags(LAST_LNK)
  {
    for (int i = 0; i <= LAST_OCTAVE_REG; i++)
      {
	m_octaveHardRegs.push_back(shared_ptr<HardRegister>(new HardRegister(i)));
      }

    initAbcFlags();
    initModFlags();
    initEssFlags();
    initMvhFlags();
    initBrslFlags();
    initCbranchFlags();
    initTssFlags();
    initLinkFlags();
  }

  OctaveFactory::~OctaveFactory()
  {}

  void
  OctaveFactory::initModFlags()
  {
    m_modFlags[OctaveFactory::MOD2] = shared_ptr<ModFlag>(new Mod2Flag());
    m_modFlags[OctaveFactory::MOD4] = shared_ptr<ModFlag>(new Mod4Flag());
    m_modFlags[OctaveFactory::MOD8] = shared_ptr<ModFlag>(new Mod8Flag());
    m_modFlags[OctaveFactory::MOD16] = shared_ptr<ModFlag>(new Mod16Flag());
    m_modFlags[OctaveFactory::MOD32] = shared_ptr<ModFlag>(new Mod32Flag());
    m_modFlags[OctaveFactory::MOD64] = shared_ptr<ModFlag>(new Mod64Flag());
    m_modFlags[OctaveFactory::MOD128] = shared_ptr<ModFlag>(new Mod128Flag());
    m_modFlags[OctaveFactory::MOD256] = shared_ptr<ModFlag>(new Mod256Flag());
    m_modFlags[OctaveFactory::MOD512] = shared_ptr<ModFlag>(new Mod512Flag());

    m_modFlags[OctaveFactory::MOD1K] = shared_ptr<ModFlag>(new Mod1KFlag());
    m_modFlags[OctaveFactory::MOD2K] = shared_ptr<ModFlag>(new Mod2KFlag());
    m_modFlags[OctaveFactory::MOD4K] = shared_ptr<ModFlag>(new Mod4KFlag());
    m_modFlags[OctaveFactory::MOD8K] = shared_ptr<ModFlag>(new Mod8KFlag());
    m_modFlags[OctaveFactory::MOD16K] = shared_ptr<ModFlag>(new Mod16KFlag());
    m_modFlags[OctaveFactory::MOD32K] = shared_ptr<ModFlag>(new Mod32KFlag());
    m_modFlags[OctaveFactory::MOD64K] = shared_ptr<ModFlag>(new Mod64KFlag());
    m_modFlags[OctaveFactory::MOD128K] = shared_ptr<ModFlag>(new Mod128KFlag());
    m_modFlags[OctaveFactory::MOD256K] = shared_ptr<ModFlag>(new Mod256KFlag());
    m_modFlags[OctaveFactory::MOD512K] = shared_ptr<ModFlag>(new Mod512KFlag());

    m_modFlags[OctaveFactory::MOD1M] = shared_ptr<ModFlag>(new Mod1MFlag());
    m_modFlags[OctaveFactory::MOD2M] = shared_ptr<ModFlag>(new Mod2MFlag());
    m_modFlags[OctaveFactory::MOD4M] = shared_ptr<ModFlag>(new Mod4MFlag());
    m_modFlags[OctaveFactory::MOD8M] = shared_ptr<ModFlag>(new Mod8MFlag());
    m_modFlags[OctaveFactory::MOD16M] = shared_ptr<ModFlag>(new Mod16MFlag());
    m_modFlags[OctaveFactory::MOD32M] = shared_ptr<ModFlag>(new Mod32MFlag());
    m_modFlags[OctaveFactory::MOD64M] = shared_ptr<ModFlag>(new Mod64MFlag());
    m_modFlags[OctaveFactory::MOD128M] = shared_ptr<ModFlag>(new Mod128MFlag());
    m_modFlags[OctaveFactory::MOD256M] = shared_ptr<ModFlag>(new Mod256MFlag());
    m_modFlags[OctaveFactory::MOD512M] = shared_ptr<ModFlag>(new Mod512MFlag());

    m_modFlags[OctaveFactory::MOD1G] = shared_ptr<ModFlag>(new Mod1GFlag());
    m_modFlags[OctaveFactory::MOD2G] = shared_ptr<ModFlag>(new Mod2GFlag());
  }

  void
  OctaveFactory::initEssFlags()
  {
    m_essFlags[OctaveFactory::ESS0] = shared_ptr<EssFlag>(new Ess0Flag(false));
    m_essFlags[OctaveFactory::ESS1] = shared_ptr<EssFlag>(new Ess1Flag(false));
    m_essFlags[OctaveFactory::ESS2] = shared_ptr<EssFlag>(new Ess2Flag(false));
    m_essFlags[OctaveFactory::ESS3] = shared_ptr<EssFlag>(new Ess3Flag(false));
    m_essFlags[OctaveFactory::ESS4] = shared_ptr<EssFlag>(new Ess4Flag(false));
    m_essFlags[OctaveFactory::ESS5] = shared_ptr<EssFlag>(new Ess5Flag(false));
    m_essFlags[OctaveFactory::ESS6] = shared_ptr<EssFlag>(new Ess6Flag(false));
    m_essFlags[OctaveFactory::ESS7] = shared_ptr<EssFlag>(new Ess7Flag(false));

    m_essFlags[OctaveFactory::ESS8] = shared_ptr<EssFlag>(new Ess8Flag(false));
    m_essFlags[OctaveFactory::ESS9] = shared_ptr<EssFlag>(new Ess9Flag(false));
    m_essFlags[OctaveFactory::ESS10] = shared_ptr<EssFlag>(new Ess10Flag(false));
    m_essFlags[OctaveFactory::ESS11] = shared_ptr<EssFlag>(new Ess11Flag(false));
    m_essFlags[OctaveFactory::ESS12] = shared_ptr<EssFlag>(new Ess12Flag(false));
    m_essFlags[OctaveFactory::ESS13] = shared_ptr<EssFlag>(new Ess13Flag(false));
    m_essFlags[OctaveFactory::ESS14] = shared_ptr<EssFlag>(new Ess14Flag(false));
    m_essFlags[OctaveFactory::ESS15] = shared_ptr<EssFlag>(new Ess15Flag(false));

    m_essFlags[OctaveFactory::ESS16] = shared_ptr<EssFlag>(new Ess16Flag(false));
    m_essFlags[OctaveFactory::ESS17] = shared_ptr<EssFlag>(new Ess17Flag(false));
    m_essFlags[OctaveFactory::ESS18] = shared_ptr<EssFlag>(new Ess18Flag(false));
    m_essFlags[OctaveFactory::ESS19] = shared_ptr<EssFlag>(new Ess19Flag(false));
    m_essFlags[OctaveFactory::ESS20] = shared_ptr<EssFlag>(new Ess20Flag(false));
    m_essFlags[OctaveFactory::ESS21] = shared_ptr<EssFlag>(new Ess21Flag(false));
    m_essFlags[OctaveFactory::ESS22] = shared_ptr<EssFlag>(new Ess22Flag(false));
    m_essFlags[OctaveFactory::ESS23] = shared_ptr<EssFlag>(new Ess23Flag(false));

    m_essFlags[OctaveFactory::ESS24] = shared_ptr<EssFlag>(new Ess24Flag(false));
    m_essFlags[OctaveFactory::ESS25] = shared_ptr<EssFlag>(new Ess25Flag(false));
    m_essFlags[OctaveFactory::ESS26] = shared_ptr<EssFlag>(new Ess26Flag(false));
    m_essFlags[OctaveFactory::ESS27] = shared_ptr<EssFlag>(new Ess27Flag(false));
    m_essFlags[OctaveFactory::ESS28] = shared_ptr<EssFlag>(new Ess28Flag(false));
    m_essFlags[OctaveFactory::ESS29] = shared_ptr<EssFlag>(new Ess29Flag(false));
    m_essFlags[OctaveFactory::ESS30] = shared_ptr<EssFlag>(new Ess30Flag(false));
    m_essFlags[OctaveFactory::ESS31] = shared_ptr<EssFlag>(new Ess31Flag(false));

    m_negatedEssFlags[OctaveFactory::ESS0] = shared_ptr<EssFlag>(new Ess0Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS1] = shared_ptr<EssFlag>(new Ess1Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS2] = shared_ptr<EssFlag>(new Ess2Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS3] = shared_ptr<EssFlag>(new Ess3Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS4] = shared_ptr<EssFlag>(new Ess4Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS5] = shared_ptr<EssFlag>(new Ess5Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS6] = shared_ptr<EssFlag>(new Ess6Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS7] = shared_ptr<EssFlag>(new Ess7Flag(true));

    m_negatedEssFlags[OctaveFactory::ESS8] = shared_ptr<EssFlag>(new Ess8Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS9] = shared_ptr<EssFlag>(new Ess9Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS10] = shared_ptr<EssFlag>(new Ess10Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS11] = shared_ptr<EssFlag>(new Ess11Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS12] = shared_ptr<EssFlag>(new Ess12Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS13] = shared_ptr<EssFlag>(new Ess13Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS14] = shared_ptr<EssFlag>(new Ess14Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS15] = shared_ptr<EssFlag>(new Ess15Flag(true));

    m_negatedEssFlags[OctaveFactory::ESS16] = shared_ptr<EssFlag>(new Ess16Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS17] = shared_ptr<EssFlag>(new Ess17Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS18] = shared_ptr<EssFlag>(new Ess18Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS19] = shared_ptr<EssFlag>(new Ess19Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS20] = shared_ptr<EssFlag>(new Ess20Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS21] = shared_ptr<EssFlag>(new Ess21Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS22] = shared_ptr<EssFlag>(new Ess22Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS23] = shared_ptr<EssFlag>(new Ess23Flag(true));

    m_negatedEssFlags[OctaveFactory::ESS24] = shared_ptr<EssFlag>(new Ess24Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS25] = shared_ptr<EssFlag>(new Ess25Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS26] = shared_ptr<EssFlag>(new Ess26Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS27] = shared_ptr<EssFlag>(new Ess27Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS28] = shared_ptr<EssFlag>(new Ess28Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS29] = shared_ptr<EssFlag>(new Ess29Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS30] = shared_ptr<EssFlag>(new Ess30Flag(true));
    m_negatedEssFlags[OctaveFactory::ESS31] = shared_ptr<EssFlag>(new Ess31Flag(true));
  }

  void
  OctaveFactory::initMvhFlags()
  {
    m_mvhFlags[OctaveFactory::C0] = shared_ptr<MvhFlag>(new C0Flag());
    m_mvhFlags[OctaveFactory::C1] = shared_ptr<MvhFlag>(new C1Flag());
    m_mvhFlags[OctaveFactory::C2] = shared_ptr<MvhFlag>(new C2Flag());
    m_mvhFlags[OctaveFactory::C3] = shared_ptr<MvhFlag>(new C3Flag());
    m_mvhFlags[OctaveFactory::C4] = shared_ptr<MvhFlag>(new C4Flag());
    m_mvhFlags[OctaveFactory::C5] = shared_ptr<MvhFlag>(new C5Flag());
    m_mvhFlags[OctaveFactory::C6] = shared_ptr<MvhFlag>(new C6Flag());
    m_mvhFlags[OctaveFactory::C7] = shared_ptr<MvhFlag>(new C7Flag());

    m_mvhFlags[OctaveFactory::C8] = shared_ptr<MvhFlag>(new C8Flag());
    m_mvhFlags[OctaveFactory::C9] = shared_ptr<MvhFlag>(new C9Flag());
    m_mvhFlags[OctaveFactory::C10] = shared_ptr<MvhFlag>(new C10Flag());
    m_mvhFlags[OctaveFactory::C11] = shared_ptr<MvhFlag>(new C11Flag());
    m_mvhFlags[OctaveFactory::C12] = shared_ptr<MvhFlag>(new C12Flag());
    m_mvhFlags[OctaveFactory::C13] = shared_ptr<MvhFlag>(new C13Flag());
    m_mvhFlags[OctaveFactory::C14] = shared_ptr<MvhFlag>(new C14Flag());
    m_mvhFlags[OctaveFactory::C15] = shared_ptr<MvhFlag>(new C15Flag());
  }

  void
  OctaveFactory::initBrslFlags()
  {
    m_brslFlags[OctaveFactory::UNLNK] = shared_ptr<BrslFlag>(new UNLNKFlag());
    m_brslFlags[OctaveFactory::PRE] = shared_ptr<BrslFlag>(new PREFlag());
    m_brslFlags[OctaveFactory::DLNK] = shared_ptr<BrslFlag>(new DLNKFlag());
    m_brslFlags[OctaveFactory::FLUSH] = shared_ptr<BrslFlag>(new FLUSHFlag());
  }

  void
  OctaveFactory::initCbranchFlags()
  {
    m_cbranchFlags[OctaveFactory::C] = shared_ptr<CbranchFlag>(new CFlag());
    m_cbranchFlags[OctaveFactory::BF] = shared_ptr<CbranchFlag>(new BFFlag());
  }

  void
  OctaveFactory::initAbcFlags()
  {
    m_abcFlags[OctaveFactory::BZ] = shared_ptr<BZFlag>(new BZFlag);
    m_abcFlags[OctaveFactory::BNC] = shared_ptr<BNCFlag>(new BNCFlag);
    m_abcFlags[OctaveFactory::BNO] = shared_ptr<BNOFlag>(new BNOFlag);
    m_abcFlags[OctaveFactory::BGEZ] = shared_ptr<BGEZFlag>(new BGEZFlag);
    m_abcFlags[OctaveFactory::BLZ] = shared_ptr<BLZFlag>(new BLZFlag);
    m_abcFlags[OctaveFactory::BNZ] = shared_ptr<BNZFlag>(new BNZFlag);
    m_abcFlags[OctaveFactory::BLEZ] = shared_ptr<BLEZFlag>(new BLEZFlag);

    m_abcCompareFlags[OctaveFactory::BALB] = shared_ptr<BALBFlag>(new BALBFlag);
    m_abcCompareFlags[OctaveFactory::BAEB] = shared_ptr<BAEBFlag>(new BAEBFlag);
    m_abcCompareFlags[OctaveFactory::BAGB] = shared_ptr<BAGBFlag>(new BAGBFlag);
    m_abcCompareFlags[OctaveFactory::BANEB] = shared_ptr<BANEBFlag>(new BANEBFlag);
    m_abcCompareFlags[OctaveFactory::BAGEB] = shared_ptr<BAGEBFlag>(new BAGEBFlag);
    m_abcCompareFlags[OctaveFactory::BALEB] = shared_ptr<BALEBFlag>(new BALEBFlag);
  }

  void
  OctaveFactory::initTssFlags()
  {
    m_tssFlags[OctaveFactory::GC1A] = shared_ptr<GC1AFlag>(new GC1AFlag);
    m_tssFlags[OctaveFactory::GC1O] = shared_ptr<GC1OFlag>(new GC1OFlag);
    m_tssFlags[OctaveFactory::GC1B] = shared_ptr<GC1BFlag>(new GC1BFlag);
    m_tssFlags[OctaveFactory::GSTICK] = shared_ptr<GSTICKFlag>(new GSTICKFlag);
    m_tssFlags[OctaveFactory::NUL] = shared_ptr<NULFlag>(new NULFlag);
    m_tssFlags[OctaveFactory::GC2A] = shared_ptr<GC2AFlag>(new GC2AFlag);
    m_tssFlags[OctaveFactory::GC2B] = shared_ptr<GC2BFlag>(new GC2BFlag);
    m_tssFlags[OctaveFactory::GC2O] = shared_ptr<GC2OFlag>(new GC2OFlag);
    m_tssFlags[OctaveFactory::GPA] = shared_ptr<GPAFlag>(new GPAFlag);
    m_tssFlags[OctaveFactory::GPU] = shared_ptr<GPUFlag>(new GPUFlag);
    m_tssFlags[OctaveFactory::GPB] = shared_ptr<GPBFlag>(new GPBFlag);
    m_tssFlags[OctaveFactory::GTA] = shared_ptr<GTAFlag>(new GTAFlag);
    m_tssFlags[OctaveFactory::GTO] = shared_ptr<GTOFlag>(new GTOFlag);
    m_tssFlags[OctaveFactory::GTB] = shared_ptr<GTBFlag>(new GTBFlag);
    m_tssFlags[OctaveFactory::FP] = shared_ptr<FPFlag>(new FPFlag);
    m_tssFlags[OctaveFactory::NG2] = shared_ptr<NG2Flag>(new NG2Flag);
    m_tssFlags[OctaveFactory::GZ] = shared_ptr<GZFlag>(new GZFlag);
    m_tssFlags[OctaveFactory::NB] = shared_ptr<NBFlag>(new NBFlag);
    m_tssFlags[OctaveFactory::NC] = shared_ptr<NCFlag>(new NCFlag);
    m_tssFlags[OctaveFactory::GW] = shared_ptr<GWFlag>(new GWFlag);
    m_tssFlags[OctaveFactory::GR] = shared_ptr<GRFlag>(new GRFlag);
    m_tssFlags[OctaveFactory::A] = shared_ptr<AFlag>(new AFlag);
    m_tssFlags[OctaveFactory::R] = shared_ptr<RFlag>(new RFlag);
    m_tssFlags[OctaveFactory::GU] = shared_ptr<GUFlag>(new GUFlag);
    m_tssFlags[OctaveFactory::T] = shared_ptr<TFlag>(new TFlag);
    m_tssFlags[OctaveFactory::RB] = shared_ptr<RBFlag>(new RBFlag);
    m_tssFlags[OctaveFactory::FB] = shared_ptr<FBFlag>(new FBFlag);
    m_tssFlags[OctaveFactory::NT] = shared_ptr<NTFlag>(new NTFlag);
    m_tssFlags[OctaveFactory::S] = shared_ptr<SFlag>(new SFlag);

    m_tssFlags[OctaveFactory::RSCH] = shared_ptr<RSCHFlag>(new RSCHFlag);
    m_tssFlags[OctaveFactory::I] = shared_ptr<IFlag>(new IFlag);
    m_tssFlags[OctaveFactory::FR] = shared_ptr<FRFlag>(new FRFlag);
    m_tssFlags[OctaveFactory::CLOSE] = shared_ptr<CLOSEFlag>(new CLOSEFlag);
    m_tssFlags[OctaveFactory::NE] = shared_ptr<NEFlag>(new NEFlag);

    m_tssFlags[OctaveFactory::OAM] = shared_ptr<OAMFlag>(new OAMFlag);
    m_tssFlags[OctaveFactory::RP] = shared_ptr<RPFlag>(new RPFlag);
    m_tssFlags[OctaveFactory::LOG] = shared_ptr<LOGFlag>(new LOGFlag);
    m_tssFlags[OctaveFactory::FPB] = shared_ptr<FPBFlag>(new FPBFlag);
    m_tssFlags[OctaveFactory::CSB] = shared_ptr<CSBFlag>(new CSBFlag);
    m_tssFlags[OctaveFactory::DELETE] = shared_ptr<DELETEFlag>(new DELETEFlag);
  }

  void
  OctaveFactory::initLinkFlags()
  {
    m_linkFlags[OctaveFactory::LNK1] = shared_ptr<LNK1Flag>(new LNK1Flag);
    m_linkFlags[OctaveFactory::LNK2] = shared_ptr<LNK2Flag>(new LNK2Flag);
    m_linkFlags[OctaveFactory::LNK3] = shared_ptr<LNK3Flag>(new LNK3Flag);
  }

  unsigned int
  OctaveFactory::getNumHardRegs() const
  {
    // LAST_OCTAVE_REG is set based on tm.h file in GCC.
    return LAST_OCTAVE_REG;
  }

  shared_ptr<OpndNull>
  OctaveFactory::createNullOperand()
  {
    return m_nullOperand;
  }

  shared_ptr<const NullRegister>
  OctaveFactory::createNullReg()
  {
    return m_nullReg;
  }

  shared_ptr<NullSymbol>
  OctaveFactory::createNullSymbol()
  {
    return m_nullSymbol;
  }

  shared_ptr<NullType>
  OctaveFactory::createNullType()
  {
    return m_nullType;
  }

  HardRegisterPtr
  OctaveFactory::createHardReg(unsigned int regno)
  {
    if ((regno ) >= 0 && (regno) <= LAST_OCTAVE_REG)
      {
	return m_octaveHardRegs[regno];

      }
    else
      throw LLIR_INTERNAL_EXCEPTION("OctaveFactory::createHardReg - Register index out of range");
  }


  shared_ptr<ModFlag>
  OctaveFactory::createModFlag(OctaveFactory::Mod flag)
  {
    if ((int) flag >= 0 && (int) flag < OctaveFactory::LAST_MOD)
      return m_modFlags[flag];
    else
      throw LLIR_INTERNAL_EXCEPTION("OctaveFactory::createModFlag - Mod index out of range");
  }

  shared_ptr<LinkFlag>
  OctaveFactory::createLnkFlag(OctaveFactory::Lnk flag)
  {
    if ((int) flag >= 0 && (int) flag < OctaveFactory::LAST_LNK)
      return m_linkFlags[flag];
    else
      throw LLIR_INTERNAL_EXCEPTION("OctaveFactory::createLnkFlag - Lnk index out of range");
  }

  shared_ptr<AbcGenericFlag>
  OctaveFactory::createAbcFlag(OctaveFactory::Abc flag)
  {
    if ((int) flag >= 0 && (int) flag < OctaveFactory::LAST_ABC)
      return m_abcFlags[flag];
    else
      throw LLIR_INTERNAL_EXCEPTION("OctaveFactory::createAbcFlag - ABC index out of range");
  }

  shared_ptr<AbcCompareFlag>
  OctaveFactory::createAbcCompareFlag(OctaveFactory::AbcCompare flag)
  {
    if ((int) flag >= 0 && (int) flag < OctaveFactory::LAST_ABC_COMPARE)
      return m_abcCompareFlags[flag];
    else
      throw LLIR_INTERNAL_EXCEPTION("OctaveFactory::createAbcCompareFlag - ABC index out of range");
  }

  shared_ptr<EssFlag>
  OctaveFactory::createEssFlag(OctaveFactory::Ess flag,
			       bool negate)
  {
    if ((int) flag >= 0 && (int) flag < OctaveFactory::LAST_ESS)
      {
	if (negate == false)
	  return m_essFlags[flag];
	else
	  return m_negatedEssFlags[flag];
      }
    else
      throw LLIR_INTERNAL_EXCEPTION("OctaveFactory::createEssFlag - ESS index out of range");
  }

  shared_ptr<MvhFlag>
  OctaveFactory::createMvhFlag(OctaveFactory::Mvh flag)
  {
    if ((int) flag >= 0 && (int) flag < OctaveFactory::LAST_MVH)
      return m_mvhFlags[flag];
    else
      throw LLIR_INTERNAL_EXCEPTION("OctaveFactory::createMvhFlag - MVH index out of range");
  }

  shared_ptr<BrslFlag> 
  OctaveFactory::createBrslFlag(OctaveFactory::Brsl flag)
  {
    if ((int) flag >= 0 && (int) flag < OctaveFactory::LAST_BRSL)
      return m_brslFlags[flag];
    else
      throw LLIR_INTERNAL_EXCEPTION("OctaveFactory::createBrslFlag - BRSL index out of range");
  }

  shared_ptr<TSSFlag>
  OctaveFactory::createTssFlag(OctaveFactory::Tss flag)
  {
    if ((int) flag >= 0 && (int) flag < OctaveFactory::LAST_TSS)
      return m_tssFlags[flag];
    else
      throw LLIR_INTERNAL_EXCEPTION("OctaveFactory::createTssFlag - TSS index out of range");
  }

  shared_ptr<CbranchFlag>
  OctaveFactory::createCbranchFlag(OctaveFactory::Cbranch flag)
  {
    if ((int) flag >= 0 && (int) flag < OctaveFactory::LAST_CBRANCH)
      return m_cbranchFlags[flag];
    else
      throw LLIR_INTERNAL_EXCEPTION("OctaveFactory::createCbranchFlag - Cbranch index out of range");
  }


  shared_ptr<CbranchFlags> 
  OctaveFactory::createCbranchFlags(shared_ptr<CbranchFlag> f1)
  {
    return shared_ptr<CbranchFlags>(new CbranchFlags(f1));
  }

  shared_ptr<CbranchFlags> 
  OctaveFactory::createCbranchFlags(shared_ptr<CbranchFlag> f1,
				    shared_ptr<CbranchFlag> f2)
  {
    return shared_ptr<CbranchFlags>(new CbranchFlags(f1,
						     f2));
  }

  shared_ptr<BrslFlags> 
  OctaveFactory::createBrslFlags(shared_ptr<BrslFlag> f1)
  {
    return shared_ptr<BrslFlags>(new BrslFlags(f1));
  }
  
  shared_ptr<BrslFlags> 
  OctaveFactory::createBrslFlags(shared_ptr<BrslFlag> f1,
				 shared_ptr<BrslFlag> f2)
  {
    return shared_ptr<BrslFlags>(new BrslFlags(f1,
					       f2));
  }

  shared_ptr<BrslFlags> 
  OctaveFactory::createBrslFlags(shared_ptr<BrslFlag> f1,
				 shared_ptr<BrslFlag> f2,
				 shared_ptr<BrslFlag> f3)
  {
    return shared_ptr<BrslFlags>(new BrslFlags(f1,
					       f2,
					       f3));
  }

  shared_ptr<BrslFlags> 
  OctaveFactory::createBrslFlags(shared_ptr<BrslFlag> f1,
				 shared_ptr<BrslFlag> f2,
				 shared_ptr<BrslFlag> f3,
				 shared_ptr<BrslFlag> f4)
  {
    return shared_ptr<BrslFlags>(new BrslFlags(f1,
					       f2,
					       f3,
					       f4));
  }

  shared_ptr<TrafficScheduleFlags> 
  OctaveFactory::createTrafficScheduleFlags()
  {
    return shared_ptr<TrafficScheduleFlags>(new TrafficScheduleFlags());
  }


  shared_ptr<FindFlag>
  OctaveFactory::createFindFlag()
  {
    return m_findFlag;
  }

  shared_ptr<CumeFlag>
  OctaveFactory::createCumeFlag()
  {
    return m_cumeFlag;
  }

  shared_ptr<DIFlag>
  OctaveFactory::createDIFlag()
  {
    return m_diFlag;
  }

  shared_ptr<SignFlag>
  OctaveFactory::createSignFlag()
  {
    return m_signFlag;
  }
  shared_ptr<CDFlag>
  OctaveFactory::createCDFlag()
  {
    return m_cdFlag;
  }

  shared_ptr<DepbFlag>
  OctaveFactory::createDepbFlag()
  {
    return m_depbFlag;
  }

  shared_ptr<SXFlag>
  OctaveFactory::createSXFlag()
  {
    return m_sxFlag;
  }

  MultiHardRegisterPtr
  OctaveFactory::createMultiHardReg(unsigned int numRegs,
				    unsigned int firstRegno)
  {
    if (numRegs == 0)
      throw LLIR_INTERNAL_EXCEPTION("Number of registers to create is 0");

    if (firstRegno > LAST_OCTAVE_REG)
      throw LLIR_INTERNAL_EXCEPTION("Register out of range");

    if (((firstRegno + numRegs) - 1) > LAST_OCTAVE_REG)
      throw LLIR_INTERNAL_EXCEPTION("Invalid register range");

    shared_ptr<MultiHardRegister> multiHardRegs(new MultiHardRegister(numRegs,
								      firstRegno));

    unsigned int hardRegNum = firstRegno;
    for (unsigned int i = 0; i < numRegs; i++,
	   hardRegNum++)
      {
	multiHardRegs->addRegister(createHardReg(hardRegNum));
      }

    return multiHardRegs;
  }

  PseudoRegisterPtr
  OctaveFactory::createPseudoReg(unsigned int regno,
				 const char *name)
  {
    if (regno <= LAST_OCTAVE_REG)
      throw LLIR_INTERNAL_EXCEPTION("Invalid register # for Pseudo");

    if (!name || *name == '\0')
      throw LLIR_INTERNAL_EXCEPTION("No name specified for Pseudo");

    ++m_numPseudoRegs;

    return shared_ptr<PseudoRegister>(new PseudoRegister(regno,
							 name));
  }

  MultiPseudoRegisterPtr
  OctaveFactory::createMultiPseudoReg(unsigned int numRegs,
				      unsigned int firstRegno,
				      const char *name)
  {
    if (numRegs == 0)
      throw LLIR_INTERNAL_EXCEPTION("Number of registers to create is 0");

    if (firstRegno <= LAST_OCTAVE_REG)
      throw LLIR_INTERNAL_EXCEPTION("Register out of range");

    if (!name || *name == '\0')
      throw LLIR_INTERNAL_EXCEPTION("No name specified for MultiPseudo");

    m_numPseudoRegs += numRegs;

    shared_ptr<MultiPseudoRegister> multiPseudoRegs(new MultiPseudoRegister(name,
									    numRegs,
									    firstRegno));

    unsigned int pseudoRegNum = firstRegno;
    for (unsigned int i = 0; i < numRegs; i++,
	   pseudoRegNum++)
      {
	multiPseudoRegs->addRegister(createPseudoReg(pseudoRegNum,
						     name));
      }

    return multiPseudoRegs;
  }

  shared_ptr<AbstractSymReg> 
  OctaveFactory::createSymReg(const char *name,

			      OctaveSymbol::ScopeQualifier scope,
			      shared_ptr<const SingleRegister> reg,
			      AbstractSymReg::SymRegConstraint sregConstraint,
			      shared_ptr<const Register> regContraintRange)
  {
    return shared_ptr<SymReg>(new SymReg(name,
					 scope,
					 reg,
					 sregConstraint,
					 regContraintRange));
  }

  shared_ptr<AbstractSymReg> 
  OctaveFactory::createMultiSymReg(const char *name,
				   OctaveSymbol::ScopeQualifier scope,
				   shared_ptr<const MultiRegister> reg,
				   AbstractSymReg::SymRegConstraint sregConstraint,
				   shared_ptr<const Register> regContraintRange)
  {
    return shared_ptr<MultiSymReg>(new MultiSymReg(name,
						   scope,
						   reg,
						   sregConstraint,

						   regContraintRange));
  }

  UnsignedImmediatePtr
  OctaveFactory::createUnsignedImmediate(unsigned long value,
					 unsigned int numBits)
  {
    if (numBits > 0 && numBits <= 32)
      return shared_ptr<UnsignedImmediate>(new UnsignedImmediate(value,
								 numBits));
    else
      throw LLIR_INTERNAL_EXCEPTION("Illegal Immediate size");
  }

  UnsignedImmediatePtr
  OctaveFactory::createUnsignedImmediate(unsigned long value,
					 unsigned long min,
					 unsigned long max,
					 unsigned int numBits)
  {
    if (numBits > 32 || numBits == 0)
      throw LLIR_INTERNAL_EXCEPTION("Illegal Immediate size");

    if (min > max)
      throw LLIR_INTERNAL_EXCEPTION("Illegal Immediate size");

    return shared_ptr<UnsignedImmediate>(new UnsignedImmediate(value,
							       min,
							       max,
							       numBits));
  }


  SignedImmediatePtr
  OctaveFactory::createSignedImmediate(long value,
				       unsigned int numBits)
  {
    if (numBits >= 0 && numBits <= 32)
      return shared_ptr<SignedImmediate>(new SignedImmediate(value,
							     numBits));
    else
      throw LLIR_INTERNAL_EXCEPTION("Illegal Immediate size");
  }

  SignedImmediatePtr
  OctaveFactory::createSignedImmediate(long value,
				       long min,
				       long max,
				       unsigned int numBits)
  {
    if (numBits > 32 || numBits == 0)
      throw LLIR_INTERNAL_EXCEPTION("Illegal Immediate size");

    if (min > max)
      throw LLIR_INTERNAL_EXCEPTION("Illegal Immediate size");

    return shared_ptr<SignedImmediate>(new SignedImmediate(value,
							   min,
							   max,
							   numBits));
  }

  shared_ptr<Base2PlusOffset>
  OctaveFactory::createBase2PlusOffsetMemory(shared_ptr<const LlirOperand> offset)
  {
    return (shared_ptr<Base2PlusOffset> (new Base2PlusOffset(offset)));
  }

  shared_ptr<Base3PlusOffset>
  OctaveFactory::createBase3PlusOffsetMemory(shared_ptr<const LlirOperand> offset)
  {
    return (shared_ptr<Base3PlusOffset> (new Base3PlusOffset(offset)));
  }

  shared_ptr<RegPlusOffsetIndirect> 
  OctaveFactory::createRegPlusOffsetMemory(shared_ptr<const Register> reg,
					   shared_ptr<const LlirOperand> offset)
  {
    return (shared_ptr<RegPlusOffsetIndirect> (new RegPlusOffsetIndirect(reg,
									 offset)));
  }

  shared_ptr<ImpliedBase2Offset> 
  OctaveFactory::createImpliedBase2OffsetMemory(shared_ptr<const LlirOperand> offset)
  {
    return (shared_ptr<ImpliedBase2Offset> (new ImpliedBase2Offset(offset)));
  }

  shared_ptr<LabelSymbol> 
  OctaveFactory::createLabelSymbol(const char* name,
				   OctaveSymbol::ScopeQualifier scope)
  {
    return shared_ptr<LabelSymbol>(new LabelSymbol(name,
						   scope));
  }

  shared_ptr<BlockSymbol> 
  OctaveFactory::createBlockSymbol(const char* name)
  {
    return shared_ptr<BlockSymbol>(new BlockSymbol(name,
						   OctaveSymbol::LOCAL));
  }

  MapToHardRegPtr 
  OctaveFactory::createMapToHardReg(const char* mapName,
				    OctaveSymbol::ScopeQualifier s,
				    shared_ptr<const Struct> tp,
				    shared_ptr<const HardRegister> hreg)
  {
    return shared_ptr<MapToHardReg>(new MapToHardReg(mapName,
						     s,
						     tp,
						     hreg));
  }
  
  MapToPseudoRegPtr 
  OctaveFactory::createMapToPseudoReg(const char* mapName,
				      OctaveSymbol::ScopeQualifier s, 
				      shared_ptr<const Struct> tp,
				      shared_ptr<const PseudoRegister> sreg)
  {
    return shared_ptr<MapToPseudoReg>(new MapToPseudoReg(mapName,
							 s,
							 tp,
							 sreg));
  }
  
  MapToMultiHardRegPtr 
  OctaveFactory::createMapToMultiHardReg(const char* mapName,
					 OctaveSymbol::ScopeQualifier s, 
					 shared_ptr<const Struct> tp,
					 shared_ptr<const MultiHardRegister> mhreg)
  {
    return shared_ptr<MapToMultiHardReg>(new MapToMultiHardReg(mapName,
							       s,
							       tp,
							       mhreg));
  }

  MapToMultiPseudoRegPtr 
  OctaveFactory::createMapToMultiPseudoReg(const char* mapName,
					   OctaveSymbol::ScopeQualifier s, 
					   shared_ptr<const Struct> tp,
					   shared_ptr<const MultiPseudoRegister> msreg)
  {
    return shared_ptr<MapToMultiPseudoReg>(new MapToMultiPseudoReg(mapName,
								   s,
								   tp,
								   msreg));
  }
    

  shared_ptr<SregisterDirective>
  OctaveFactory::createSregisterDirective(unsigned int lineNum,
					  unsigned int srcLineNum,
					  const char* srcFileName,
					  const char *name,
					  shared_ptr<const Register> reg,
					  AbstractSymReg::SymRegConstraint symRegConstraint,
					  shared_ptr<const Register> constraintRegRange)
  {
    return shared_ptr<SregisterDirective> (new SregisterDirective(lineNum,
								  srcLineNum,
								  srcFileName,
								  name,
								  reg,
								  symRegConstraint,
								  constraintRegRange ));
  }

  shared_ptr<LlirLineControlDirective>
  OctaveFactory::createLineCtrlDirective(unsigned int lineNum,
					 unsigned int lineCntrlNum,
					 const char *asmFileName,
					 LlirLineControlDirective::LineCntrlFlagType flag)
  {
    return shared_ptr<LlirLineControlDirective>(new LlirLineControlDirective(lineNum,
									     lineCntrlNum,
									     asmFileName,
									     flag));
  }

  shared_ptr<NullNode>
  OctaveFactory::createNullNode(unsigned int lineNum,
				unsigned int srcLineNum,
				const char* srcFileName)
  {
    return shared_ptr<NullNode>(new NullNode(lineNum,
					     srcLineNum,
					     srcFileName));
  }

  shared_ptr<NewLineNode> 
  OctaveFactory::createNewLineNode(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName,
				   const char* newLineStr)
  {
    return shared_ptr<NewLineNode>(new NewLineNode(lineNum,
						   srcLineNum,
						   srcFileName,
						   newLineStr));
  }

  shared_ptr<OctaveInstruction>
  OctaveFactory::createNullInstruction(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName)
  {
    return  shared_ptr<NullInstruction>(new NullInstruction(lineNum,
							    srcLineNum,
							    srcFileName));
  }

  shared_ptr<LlirOctaveBlock>
  OctaveFactory::createBlock(unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName)
  {
    return shared_ptr<LlirOctaveBlock>(new OctaveBlock(lineNum,
						       srcLineNum,
						       srcFileName));
  }

  shared_ptr<LlirOctaveBlock>
  OctaveFactory::createBlock(const char *blockName,
			     unsigned int lineNum,
			     unsigned int srcLineNum,
			     const char* srcFileName)
  {
    return shared_ptr<LlirOctaveBlock>(new OctaveBlock(blockName,
						       lineNum,
						       srcLineNum,
						       srcFileName));
  }

  shared_ptr<LlirOctaveBlock>
  OctaveFactory::createMacroBlock(unsigned int lineNum,
				  unsigned int srcLineNum,
				  const char* srcFileName)
  {
    return shared_ptr<LlirOctaveBlock>(new OctaveMacroBlock(lineNum,
							    srcLineNum,
							    srcFileName));
  }

  shared_ptr<LlirOctaveBlock>
  OctaveFactory::createGlobalBlock()
  {
    return shared_ptr<LlirOctaveBlock>(new OctaveImplicitBlock());
  }

  shared_ptr<Struct>
  OctaveFactory::createStruct(const char *name)
  {
    return shared_ptr<Struct>(new Struct(name));
  }

  shared_ptr<Align>
  OctaveFactory::createAlignDirective(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName,
				      unsigned int alignSize)
  {
    return shared_ptr<Align>(new Align(lineNum,
				       srcLineNum,
				       srcFileName,
				       alignSize));
  }

  shared_ptr<Ref>
  OctaveFactory::createRefDirective(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName,
				    const char *name)
  {
    return shared_ptr<Ref>(new Ref(lineNum,
				   srcLineNum,
				   srcFileName,
				   name));
  }

  shared_ptr<List>
  OctaveFactory::createListDirective(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName)
  {
    return shared_ptr<List>(new List(lineNum,
				     srcLineNum,
				     srcFileName));
  }

  shared_ptr<LocalLabel>
  OctaveFactory::createLocalLabelDirective(unsigned int lineNum,
					   unsigned int srcLineNum,
					   const char* srcFileName,
					   const char *name,
					   const char* mangledName)
  {
    return shared_ptr<LocalLabel>(new LocalLabel(lineNum,
						 srcLineNum,
						 srcFileName,
						 name,
						 mangledName));
  }

  shared_ptr<GlobalLabel>
  OctaveFactory::createGlobalLabelDirective(unsigned int lineNum,
					    unsigned int srcLineNum,
					    const char* srcFileName,
					    const char *name,
					    const char* mangledName)
  {
    return shared_ptr<GlobalLabel>(new GlobalLabel(lineNum,
						   srcLineNum,
						   srcFileName,
						   name,
						   mangledName));
  }

  shared_ptr<FileScopeLabel>
  OctaveFactory::createFileScopeLabelDirective(unsigned int lineNum,
					       unsigned int srcLineNum,
					       const char* srcFileName,
					       const char *name,
					       const char* mangledName)
  {
    return shared_ptr<FileScopeLabel>(new FileScopeLabel(lineNum,
							 srcLineNum,
							 srcFileName,
							 name,
							 mangledName));
  }

  shared_ptr<EndBlock>
  OctaveFactory::createEndBlockDirective(unsigned int lineNum,
					 unsigned int srcLineNum,
					 const char* srcFileName)
  {
    return shared_ptr<EndBlock>(new UnNamedEndBlock(lineNum,
						    srcLineNum,
						    srcFileName));
  }

  shared_ptr<EndBlock>
  OctaveFactory::createEndBlockDirective(unsigned int lineNum,
					 unsigned int srcLineNum,
					 const char* srcFileName,
					 const char *blockName)
  {
    return shared_ptr<EndBlock>(new NamedEndBlock(lineNum,
						  srcLineNum,
						  srcFileName,
						  blockName));
  }

  shared_ptr<Ascii>
  OctaveFactory::createAsciiDirective(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName,
				      const char *string)
  {
    return shared_ptr<Ascii>(new Ascii(lineNum,
				       srcLineNum,
				       srcFileName,
				       string));
  }

  shared_ptr<EndMacro>
  OctaveFactory::createEndMacroDirective(unsigned int lineNum,
					 unsigned int srcLineNum,
					 const char* srcFileName)
  {
    return shared_ptr<EndMacro>(new EndMacro(lineNum,
					     srcLineNum,
					     srcFileName));
  }

  shared_ptr<NoList>
  OctaveFactory::createNoListDirective(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName)
  {
    return shared_ptr<NoList>(new NoList(lineNum,
					 srcLineNum,
					 srcFileName));
  }

  shared_ptr<Datum>
  OctaveFactory::createDatum(shared_ptr<const LlirExpr> d,
			     unsigned int repeatCount)
  {
    return shared_ptr<Datum>(new Datum(d,
				       repeatCount));
  }

  shared_ptr<AllocMemoryDirective>
  OctaveFactory::createByteDirective(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName)
  {
    return shared_ptr<Byte>(new Byte(lineNum,
				     srcLineNum,
				     srcFileName));
  }

  shared_ptr<AllocMemoryDirective>
  OctaveFactory::createWordDirective(unsigned int lineNum,
				     unsigned int srcLineNum,
				     const char* srcFileName)
  {
    return shared_ptr<Word>(new Word(lineNum,
				     srcLineNum,
				     srcFileName));
  }

  shared_ptr<AllocMemoryDirective>
  OctaveFactory::createHalfWordDirective(unsigned int lineNum,
					 unsigned int srcLineNum,
					 const char* srcFileName)
  {
    return shared_ptr<HalfWord>(new HalfWord(lineNum,
					     srcLineNum,
					     srcFileName));
  }

  shared_ptr<OrgDirective>
  OctaveFactory::createOrgDirective(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName,
				    unsigned int numBytes)
  {
    return shared_ptr<Org>(new Org(lineNum,
				   srcLineNum,
				   srcFileName,
				   numBytes));
  }

  shared_ptr<OrgDirective>
  OctaveFactory::createOrgDirective(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName,
				    unsigned int numBytes,
				    unsigned int fillValue)
  {
    return shared_ptr<OrgWithFillValue>(new OrgWithFillValue(lineNum,
							     srcLineNum,
							     srcFileName,
							     numBytes,
							     fillValue));
  }

  shared_ptr<Section>
  OctaveFactory::createDataSection(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName)
  {
    return shared_ptr<Section>(new Data(lineNum,
					srcLineNum,
					srcFileName));
  }

  shared_ptr<Section>
  OctaveFactory::createTextSection(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName)
  {
    return shared_ptr<Section>(new Text(lineNum,
					srcLineNum,
					srcFileName));
  }

  shared_ptr<Section>
  OctaveFactory::createCommSection(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName,
				   const char *name,
				   unsigned int size)
  {
    return shared_ptr<Section>(new Comm(lineNum,
					srcLineNum,
					srcFileName,
					name,
					size));
  }

  shared_ptr<Section>
  OctaveFactory::createLcommSection(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName,
				    const char *name,
				    unsigned int size)
  {
    return shared_ptr<Section>(new Lcomm(lineNum,
					 srcLineNum,
					 srcFileName,
					 name,
					 size));
  }

  shared_ptr<Section>
  OctaveFactory::createNamedSection(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName,
				    const char *name)
  {
    return shared_ptr<Section>(new NamedSection(lineNum,
						srcLineNum,
						srcFileName,
						name));
  }

  shared_ptr<MapDirective> 
  OctaveFactory::createMapDirective(unsigned int lineNum,
				    unsigned int srcLineNum,
				    const char* srcFileName,
				    const char *mapPath,
				    const char *mapName,
				    shared_ptr<MapSymbol> symbol)
  {
    return shared_ptr<MapDirective>(new MapDirective(lineNum,
						     srcLineNum,
						     srcFileName,
						     mapPath,
						     mapName,
						     symbol));
  }


  shared_ptr<ScopedMapDirective> 
  OctaveFactory::createScopedMapDirective(unsigned int lineNum,
					  unsigned int srcLineNum,
					  const char* srcFileName,
					  const char *mapPath,
					  const char *mapName,
					  shared_ptr<MapSymbol> symbol)
  {
    return shared_ptr<ScopedMapDirective>(new ScopedMapDirective(lineNum,
								 srcLineNum,
								 srcFileName,
								 mapPath,
								 mapName,
								 symbol));
  }


  shared_ptr<UnmapDirective>
  OctaveFactory::createUnmapDirective(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName,
				      const char *mapName)
  {
    return shared_ptr<UnmapDirective>(new UnmapDirective(lineNum,
							 srcLineNum,
							 srcFileName,
							 mapName));
  }

  shared_ptr<StructBeginDirective>
  OctaveFactory::createStructBeginDirective(unsigned int lineNum,
					    unsigned int srcLineNum,
					    const char* srcFileName,
					    const char *structName)
  {
    return shared_ptr<StructBeginDirective>(new StructBeginDirective(lineNum,
								     srcLineNum,
								     srcFileName,
								     structName));
  }
  
  shared_ptr<StructEndDirective>
  OctaveFactory::createStructEndDirective(unsigned int lineNum,
					  unsigned int srcLineNum,
					  const char* srcFileName)
  {
    return shared_ptr<StructEndDirective>(new StructEndDirective(lineNum,
								 srcLineNum,
								 srcFileName));
  }

  shared_ptr<ElementDirective> 
  OctaveFactory::createElementDirective(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName,
					shared_ptr<Element> elemDecl)
  {
    return shared_ptr<ElementDirective>(new ElementDirective(lineNum,
							     srcLineNum,
							     srcFileName,
							     elemDecl));
  }


  shared_ptr<MeetsDirective>  
  OctaveFactory::createMeetsDirective(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName,
				      const char* testedPath,
				      const char* referencePath)
  {
    return shared_ptr<MeetsDirective>(new MeetsDirective(lineNum,
							 srcLineNum,
							 srcFileName,
							 testedPath,
							 referencePath));
  }
  
  shared_ptr<AssertDirective>  
  OctaveFactory::createAssertDirective(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName,
				       shared_ptr<const LlirOperand> expr,
				       const char* assertMsg)
  {
    return shared_ptr<AssertDirective>(new AssertDirective(lineNum,
							   srcLineNum,
							   srcFileName,
							   expr,
							   assertMsg));
  }
  
  shared_ptr<WarningDirective>  
  OctaveFactory::createWarningDirective(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName,
					const char* warningMsg)
  {
    return shared_ptr<WarningDirective>(new WarningDirective(lineNum,
							     srcLineNum,
							     srcFileName,
							     warningMsg));
  }
  
  shared_ptr<ErrorDirective>  
  OctaveFactory::createErrorDirective(unsigned int lineNum,
				      unsigned int srcLineNum,
				      const char* srcFileName,
				      const char* errorMsg)
  {
    return shared_ptr<ErrorDirective>(new ErrorDirective(lineNum,
							 srcLineNum,
							 srcFileName,
							 errorMsg));
  }
  

  shared_ptr<const MultiRegister>
  OctaveFactory::convertSingleToDmaMultiReg(shared_ptr<const Register> reg)
  {
    shared_ptr<const MultiRegister> mr;
    shared_ptr<const SingleRegister> sr;

    if ((mr = shared_dynamic_cast<const MultiRegister>(reg)))
      {
	return shared_static_cast<const MultiRegister>(reg);
      }
    else if ((sr = shared_dynamic_cast<const SingleRegister>(reg)))
      {
	/* There's no "create multi reg",
	   have to create one of the
	   * derived classes.  */
	shared_ptr<const HardRegister> shr;
	shared_ptr<const PseudoRegister> spr;

	if ((shr = shared_dynamic_cast<const HardRegister>(reg)))
	  {
	    return (createMultiHardReg(2,
				       shr->getRegNum()));
	  }
	else if ((spr = shared_dynamic_cast<const PseudoRegister>(reg)))
	  {
	    return (createMultiPseudoReg(2,
					 spr->getRegNum(),
					 spr->getRegName().c_str()));
	  }
      }
    else
      {
	if(shared_dynamic_cast<const NullRegister>(reg))
	  {
	    //some error might have occured in the input source
	    //and instruction might be having a null register

	    //pass on a dummy multi register...
	    return (createMultiHardReg(2,
				       0));
	  }
	else
	  {
	    throw LLIR_INTERNAL_EXCEPTION("Illegal Register for conversion");
	  }
      }

    return mr;  // to supress compiler warning...
	
  }

  shared_ptr<const MultiRegister>
  OctaveFactory::convertSingleToMultiReg(shared_ptr<const Register> reg)
  {
    shared_ptr<const MultiRegister> mr;
    shared_ptr<const SingleRegister> sr;

    if ((mr = shared_dynamic_cast<const MultiRegister>(reg)))
      {
	return shared_static_cast<const MultiRegister>(reg);
      }
    else if ((sr = shared_dynamic_cast<const SingleRegister>(reg)))
      {
	/* There's no "create multi reg",
	   have to create one of the
	   * derived classes.  */
	shared_ptr<const HardRegister> shr;
	shared_ptr<const PseudoRegister> spr;

	if ((shr = shared_dynamic_cast<const HardRegister>(reg)))
	  {
	    return (createMultiHardReg(1,
				       shr->getRegNum()));
	  }
	else if ((spr = shared_dynamic_cast<const PseudoRegister>(reg)))
	  {
	    return (createMultiPseudoReg(1,
					 spr->getRegNum(),
					 spr->getRegName().c_str()));
	  }
	else
	  {
	    throw LLIR_INTERNAL_EXCEPTION("Illegal Register for conversion");
	  }
      }
    else
      {
	if(shared_dynamic_cast<const NullRegister>(reg))
	  {
	    //some error might have occured in the input source
	    //and instruction might be having a null register

	    //pass on a dummy multi register...
	    return (createMultiHardReg(2,
				       0));
	  }
	else
	  {
	    throw LLIR_INTERNAL_EXCEPTION("Illegal Register for conversion");
	  }
      }

    return mr;  // to supress compiler warning...
	
  }

  shared_ptr<OpndLabel> 
  OctaveFactory::createLabel(const char *name)
  {
    if (!name || *name == '\0')
      throw LLIR_INTERNAL_EXCEPTION("No name specified for Label");

    return (shared_ptr<OpndLabel> (new OpndLabel(name)));
  }

  shared_ptr<PlusOp> 
  OctaveFactory::createPlusExpr(shared_ptr<const LlirOperand> lhs,
				shared_ptr<const LlirOperand> rhs)
  {
    return (shared_ptr<PlusOp>(new PlusOp(lhs,rhs)));
  }

  shared_ptr<MinusOp> 
  OctaveFactory::createMinusExpr(shared_ptr<const LlirOperand> lhs,
				 shared_ptr<const LlirOperand> rhs)
  {
    return (shared_ptr<MinusOp>(new MinusOp(lhs,rhs)));
  }

  shared_ptr<MultiplyOp> 
  OctaveFactory::createMultiplyExpr(shared_ptr<const LlirOperand> lhs,
				    shared_ptr<const LlirOperand> rhs)
  {
    return (shared_ptr<MultiplyOp>(new MultiplyOp(lhs,rhs)));
  }

  shared_ptr<DivOp> 
  OctaveFactory::createDivExpr(shared_ptr<const LlirOperand> lhs,
			       shared_ptr<const LlirOperand> rhs)
  {
    return (shared_ptr<DivOp>(new DivOp(lhs,rhs)));
  }

  shared_ptr<ModulusOp> 
  OctaveFactory::createModulusExpr(shared_ptr<const LlirOperand> lhs,
				   shared_ptr<const LlirOperand> rhs)
  {
    return (shared_ptr<ModulusOp>(new ModulusOp(lhs,rhs)));
  }

  shared_ptr<LeftShiftOp> 
  OctaveFactory::createLeftShiftExpr(shared_ptr<const LlirOperand> lhs,
				     shared_ptr<const LlirOperand> rhs)
  {
    return (shared_ptr<LeftShiftOp>(new LeftShiftOp(lhs,rhs)));
  }

  shared_ptr<RightShiftOp> 
  OctaveFactory::createRightShiftExpr(shared_ptr<const LlirOperand> lhs,
				      shared_ptr<const LlirOperand> rhs)
  {
    return (shared_ptr<RightShiftOp>(new RightShiftOp(lhs,rhs)));
  }

  shared_ptr<BitWiseAndOp> 
  OctaveFactory::createBitWiseAndExpr(shared_ptr<const LlirOperand> lhs,
				      shared_ptr<const LlirOperand> rhs)
  {
    return (shared_ptr<BitWiseAndOp>(new BitWiseAndOp(lhs,
						      rhs)));
  }

  shared_ptr<BitWiseOrOp> 
  OctaveFactory::createBitWiseOrExpr(shared_ptr<const LlirOperand>  lhs,
				     shared_ptr<const LlirOperand> rhs)
  {
    return (shared_ptr<BitWiseOrOp>(new BitWiseOrOp(lhs,
						    rhs)));
  }

  shared_ptr<BitWiseXorOp> 
  OctaveFactory::createBitWiseXorExpr(shared_ptr<const LlirOperand> lhs,
				      shared_ptr<const LlirOperand> rhs)
  {
    return (shared_ptr<BitWiseXorOp>(new BitWiseXorOp(lhs,
						      rhs)));
  }

  shared_ptr<ParenthesesOp> 
  OctaveFactory::createParenthesesExpr(shared_ptr<const LlirOperand> op)
  {
    return (shared_ptr<ParenthesesOp>(new ParenthesesOp(op)));
  }

  shared_ptr<UnaryMinusOp>
  OctaveFactory::createUnaryMinusExpr(shared_ptr<const LlirOperand> op)
  {
    return (shared_ptr<UnaryMinusOp>(new UnaryMinusOp(op)));
  }


  shared_ptr<Lo17Op> 
  OctaveFactory::createLo17Expr(shared_ptr<const LlirOperand> op)
  {
    return (shared_ptr<Lo17Op>(new Lo17Op(op)));
  }

  shared_ptr<Hi16Op> 
  OctaveFactory::createHi16Expr(shared_ptr<const LlirOperand> op)
  {
    return (shared_ptr<Hi16Op>(new Hi16Op(op)));
  }

  shared_ptr<Lo16Op> 
  OctaveFactory::createLo16Expr(shared_ptr<const LlirOperand> op)
  {
    return (shared_ptr<Lo16Op>(new Lo16Op(op)));
  }

  shared_ptr<WordOp> 
  OctaveFactory::createWordExpr(shared_ptr<const LlirOperand> op)
  {
    return (shared_ptr<WordOp>(new WordOp(op)));
  }


  shared_ptr<LabelList>
  OctaveFactory::createLabelList()
  {
    return shared_ptr<LabelList>(new LabelList());
  }

  shared_ptr<RegList>
  OctaveFactory::createRegList()
  {
    return shared_ptr<RegList>(new RegList());
  }

  shared_ptr<GlobalRegisterList>
  OctaveFactory::createGlobalRegisterList(shared_ptr<RegList> regList)
  {
    return shared_ptr<GlobalRegisterList>(new GlobalRegisterList(regList));
  }


  shared_ptr<ArgList> 
  OctaveFactory::createArgList(shared_ptr<RegList> regList)
  {
    return shared_ptr<ArgList>(new ArgList(regList));
  }
  
  shared_ptr<ResultList> 
  OctaveFactory::createResultList(shared_ptr<RegList> regList)
  {
    return shared_ptr<ResultList>(new ResultList(regList));
  }
  

  shared_ptr<ScratchList> 
  OctaveFactory::createScratchList(shared_ptr<RegList> regList)
  {
    return shared_ptr<ScratchList>(new ScratchList(regList));
  }


  shared_ptr<RegLnksListToSPRAM> 
  OctaveFactory::createRegLnksListToSPRAM(shared_ptr<RegList> regListLnk1,
					  shared_ptr<RegList> regListLnk2,
					  shared_ptr<RegList> regListLnk3)
  {
    return shared_ptr<RegLnksListToSPRAM>(new RegLnksListToSPRAM(regListLnk1,
								 regListLnk2,
								 regListLnk3));
  }

  shared_ptr<RegLnksListToLockedSPRAM> 
  OctaveFactory::createRegLnksListToLockedSPRAM(shared_ptr<RegList> regListLnk1,
						shared_ptr<RegList> regListLnk2,
						shared_ptr<RegList> regListLnk3)
  {
    return shared_ptr<RegLnksListToLockedSPRAM>(new RegLnksListToLockedSPRAM(regListLnk1,
									     regListLnk2,
									     regListLnk3));
  }

  shared_ptr<RegLnksListToSRAM> 
  OctaveFactory::createRegLnksListToSRAM(shared_ptr<RegList> regListLnk1,
					 shared_ptr<RegList> regListLnk2,
					 shared_ptr<RegList> regListLnk3)
  {
    return shared_ptr<RegLnksListToSRAM>(new RegLnksListToSRAM(regListLnk1,
							       regListLnk2,
							       regListLnk3));
  }
  
  shared_ptr<RegLnksListToSDRAM> 
  OctaveFactory::createRegLnksListToSDRAM(shared_ptr<RegList> regListLnk1,
					  shared_ptr<RegList> regListLnk2,
					  shared_ptr<RegList> regListLnk3)
  {
    return shared_ptr<RegLnksListToSDRAM>(new RegLnksListToSDRAM(regListLnk1,
								 regListLnk2,
								 regListLnk3));
  }

  shared_ptr<RegLnksListToCCRAM> 
  OctaveFactory::createRegLnksListToCCRAM(shared_ptr<RegList> regListLnk1,
					  shared_ptr<RegList> regListLnk2,
					  shared_ptr<RegList> regListLnk3)
  {
    return shared_ptr<RegLnksListToCCRAM>(new RegLnksListToCCRAM(regListLnk1,
								 regListLnk2,
								 regListLnk3));
  }

  shared_ptr<RegLnksListToLockedCCRAM> 
  OctaveFactory::createRegLnksListToLockedCCRAM(shared_ptr<RegList> regListLnk1,
						shared_ptr<RegList> regListLnk2,
						shared_ptr<RegList> regListLnk3)
  {
    return shared_ptr<RegLnksListToLockedCCRAM>(new RegLnksListToLockedCCRAM(regListLnk1,
									     regListLnk2,
									     regListLnk3));
  }

  shared_ptr<RegLnksListToSIO> 
  OctaveFactory::createRegLnksListToSIO(shared_ptr<RegList> regListLnk1,
					shared_ptr<RegList> regListLnk2,
					shared_ptr<RegList> regListLnk3)
  {
    return shared_ptr<RegLnksListToSIO>(new RegLnksListToSIO(regListLnk1,
							     regListLnk2,
							     regListLnk3));
  }




  shared_ptr<GlobalDirective> 
  OctaveFactory::createGlobalDirective(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName,					  
				       shared_ptr<const GlobalRegisterList> globalReg_List,
				       shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
				       shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
				       shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
				       shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
				       shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
				       shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
				       shared_ptr<const RegLnksListToSIO> lnkToSIO_List)
  {
    return shared_ptr<GlobalDirective>(new GlobalDirective(lineNum,
							   srcLineNum,
							   srcFileName,
							   globalReg_List,
							   lnkToSPRAM_List,
							   lnkToLocked_SPRAM_List,
							   lnkToSRAM_List,
							   lnkToSDRAM_List,
							   lnkToCCRAM_List,
							   lnkToLocked_CCRAM_List,
							   lnkToSIO_List));
  }
    
  shared_ptr<MultipleEntryEvh> 
  OctaveFactory::createMultipleEntryEvh(unsigned int lineNum,
					unsigned int srcLineNum,
					const char* srcFileName,					  
					shared_ptr<const LabelList> labelList,
					shared_ptr<const ArgList> argList,
					shared_ptr<const ResultList> resultList,
					shared_ptr<const ScratchList> scratchList,
					shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
					shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
					shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
					shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
					shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
					shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
					shared_ptr<const RegLnksListToSIO> lnkToSIO_List)
  {
    return shared_ptr<MultipleEntryEvh>(new MultipleEntryEvh(lineNum,
							     srcLineNum,
							     srcFileName,
							     LAST_OCTAVE_REG+1,
							     0,
							     labelList,
							     argList,
							     resultList,
							     scratchList,
							     lnkToSPRAM_List,
							     lnkToLocked_SPRAM_List,
							     lnkToSRAM_List,
							     lnkToSDRAM_List,
							     lnkToCCRAM_List,
							     lnkToLocked_CCRAM_List,
							     lnkToSIO_List));
  }
    
  shared_ptr<EndEvhDirective> 
  OctaveFactory::createEndEvhDirective(unsigned int lineNum,
				       unsigned int srcLineNum,
				       const char* srcFileName,					  
				       const char* label)
  {
    return shared_ptr<EndEvhDirective>(new EndEvhDirective(lineNum,
							   srcLineNum,
							   srcFileName,

							   label));
  }

  shared_ptr<MultipleEntryFunction> 
  OctaveFactory::createMultipleEntryFunction(unsigned int lineNum,
					     unsigned int srcLineNum,
					     const char* srcFileName,
					     shared_ptr<const LabelList> labelList,
					     shared_ptr<const ArgList> argList,
					     shared_ptr<const ResultList> resultList,
					     shared_ptr<const ScratchList> scratchList,
					     shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
					     shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
					     shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
					     shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
					     shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
					     shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
					     shared_ptr<const RegLnksListToSIO> lnkToSIO_List)
  {
    return shared_ptr<MultipleEntryFunction>(new MultipleEntryFunction(lineNum,
								       srcLineNum,
								       srcFileName,
								       LAST_OCTAVE_REG+1,
								       0,
								       labelList,
								       argList,
								       resultList,
								       scratchList,
								       lnkToSPRAM_List,
								       lnkToLocked_SPRAM_List,
								       lnkToSRAM_List,
								       lnkToSDRAM_List,
								       lnkToCCRAM_List,
								       lnkToLocked_CCRAM_List,
								       lnkToSIO_List));
  }


    
  shared_ptr<EndEntryDirective> 
  OctaveFactory::createEndEntryDirective(unsigned int lineNum,
					 unsigned int srcLineNum,
					 const char* srcFileName,					  
					 const char* label)
  {
    return shared_ptr<EndEntryDirective>(new EndEntryDirective(lineNum,
							       srcLineNum,
							       srcFileName,
							       label));
  }

  shared_ptr<PrototypeDirective> 
  OctaveFactory::createPrototypeDirective(unsigned int lineNum,
					  unsigned int srcLineNum,
					  const char* srcFileName,
					  shared_ptr<const LabelList> labelList,
					  shared_ptr<const ArgList> argList,
					  shared_ptr<const ResultList> resultList,
					  shared_ptr<const ScratchList> scratchList,
					  shared_ptr<const RegLnksListToSPRAM> lnkToSPRAM_List,
					  shared_ptr<const RegLnksListToLockedSPRAM> lnkToLocked_SPRAM_List,
					  shared_ptr<const RegLnksListToSRAM> lnkToSRAM_List,
					  shared_ptr<const RegLnksListToSDRAM> lnkToSDRAM_List,
					  shared_ptr<const RegLnksListToCCRAM> lnkToCCRAM_List,
					  shared_ptr<const RegLnksListToLockedCCRAM> lnkToLocked_CCRAM_List,
					  shared_ptr<const RegLnksListToSIO> lnkToSIO_List)
  {
    return shared_ptr<PrototypeDirective>(new PrototypeDirective(lineNum,
								 srcLineNum,
								 srcFileName,
								 labelList,
								 argList,
								 resultList,
								 scratchList,
								 lnkToSPRAM_List,
								 lnkToLocked_SPRAM_List,
								 lnkToSRAM_List,
								 lnkToSDRAM_List,
								 lnkToCCRAM_List,
								 lnkToLocked_CCRAM_List,
								 lnkToSIO_List));

  }
    
  shared_ptr<IndirectCallTargetList> 
  OctaveFactory::createIndirectCallTargetList(shared_ptr<const LabelList> labelList)
  {
    return shared_ptr<IndirectCallTargetList>(new IndirectCallTargetList(labelList));
  }
    
   
  shared_ptr<JtableBegin> 
  OctaveFactory::createJtableBegin(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName,
				   shared_ptr<LabelList> labelList)
  {
    return shared_ptr<JtableBegin>(new JtableBegin(lineNum,
						   srcLineNum,
						   srcFileName,
						   labelList));
  }
    
   
  shared_ptr<JtableEnd> 
  OctaveFactory::createJtableEnd(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName)
  {
    return shared_ptr<JtableEnd>(new JtableEnd(lineNum,
					       srcLineNum,
					       srcFileName));
  }
    
    
   
  shared_ptr<JtableRelativeBegin> 
  OctaveFactory::createJtableRelativeBegin(unsigned int lineNum,
				   unsigned int srcLineNum,
				   const char* srcFileName,
				   shared_ptr<LabelList> labelList)
  {
    return shared_ptr<JtableRelativeBegin>(new JtableRelativeBegin(lineNum,
								   srcLineNum,
								   srcFileName,
								   labelList));
  }
    
   
  shared_ptr<JtableRelativeEnd> 
  OctaveFactory::createJtableRelativeEnd(unsigned int lineNum,
				 unsigned int srcLineNum,
				 const char* srcFileName)
  {
    return shared_ptr<JtableRelativeEnd>(new JtableRelativeEnd(lineNum,
							       srcLineNum,
							       srcFileName));
  }
    

}
