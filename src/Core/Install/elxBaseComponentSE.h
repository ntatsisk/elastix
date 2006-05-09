#ifndef __elxBaseComponentSE_h
#define __elxBaseComponentSE_h

#include "elxBaseComponent.h"
#include "itkObject.h"


namespace elastix
{
  using namespace itk;


	/**
	 * \class BaseComponentSE
	 *
	 * \brief The BaseComponentSE class is a base class for elastix
	 * components that provides some basic functionality.
	 *
	 * 
	 */

	template <class TElastix>
		class BaseComponentSE : public BaseComponent
	{
	public:

		/** Standard stuff.*/
		typedef BaseComponentSE		Self;
		typedef BaseComponent			Superclass;

		/** Elastix typedef's.*/
		typedef TElastix												ElastixType;
		typedef typename ElastixType::Pointer		ElastixPointer;

		/** ConfigurationType.*/
		typedef typename ElastixType::ConfigurationType			ConfigurationType;
		typedef typename ElastixType::ConfigurationPointer	ConfigurationPointer;

		/** RegistrationType; NB: this is the RegistrationBASEtype,
		 * not an itk::Object or something like that.
		 */
		typedef typename ElastixType::RegistrationBaseType	RegistrationType;
		typedef RegistrationType *													RegistrationPointer;

		/**
		 * Get/Set functions for Elastix.
		 * The Set-functions cannot be defined with the itkSetObjectMacro,
		 * since this class does not derive from itk::Object and 
		 * thus does not have a ::Modified() method.
		 *
		 * This method checks if this instance of the class can be casted
		 * (dynamically) to an itk::Object. If yes, it calls ::Modified()
		 *
		 * Besides setting m_Elastix, this method also sets m_Configuration
		 * and m_Registration.
		 */
		virtual void SetElastix( ElastixType * _arg );

		/** itkGetObjectMacro( Elastix, ElastixType );
		 * without the itkDebug call.
		 */
		virtual ElastixType * GetElastix(void)
		{
			return this->m_Elastix.GetPointer();
		}

		/** itkGetObjectMacro(Configuration, ConfigurationType);*/
		virtual ConfigurationType * GetConfiguration(void)
		{
			return this->m_Configuration.GetPointer();
		}

		/** Set the configuration. Added for tranformix. */
		virtual void SetConfiguration( ConfigurationType * _arg );
		
		/** Get a pointer to the Registration component.*/
		virtual RegistrationPointer GetRegistration(void)
		{
			return this->m_Registration;
		}

	protected:

		BaseComponentSE();
		virtual ~BaseComponentSE() {}

		ElastixPointer				m_Elastix;
		ConfigurationPointer	m_Configuration;
		RegistrationPointer		m_Registration;

	private:

		BaseComponentSE( const Self& );		// purposely not implemented
		void operator=( const Self& );		// purposely not implemented

	}; // end class BaseComponentSE


} //end namespace elastix


#ifndef ITK_MANUAL_INSTANTIATION
#include "elxBaseComponentSE.hxx"
#endif


#endif // end #ifndef __elxBaseComponentSE_h

