#ifndef FACTORY_H
#define FACTORY_H

#include <QList>
#include <QMap>

typedef QMap< QString, QString > Informations;
typedef QMapIterator< QString, QString > InformationsIterator;



/**
 *	A generic factory.
 */

template< class Product >
class Factory {

	public:

		typedef Product* ( *CreateFunction )( );

	private:

		class ProductMetaType {

			public:

				/**
				 *	Default constructor.
				 */

				ProductMetaType( ) { }



				/**
				 *	Constructor.
				 *
				 *	@param name Name of the product.
				 *	@param description Description of the product.
				 *	@param function Helper function to create the product.
				 */

				ProductMetaType(
					const QString& name,
					const QString& description,
					CreateFunction function
				) :
					_name( name ),
					_description( description ),
					_create( function )
				{ }



				/**
				 *	Returns the name of the product.
				 *
				 *	@return Product name.
				 */

				QString name( ) const{

					return _name;
				}



				/**
				 *	Returns the description of the product.
				 *
				 *	@return Product description.
				 */

				QString description( ) const {

					return _description;
				}



				/**
				 *	Returns an instance of a product.
				 *
				 *	@return Product instance.
				 */

				Product* create( ) const {

					return _create( );
				}

			private:

				QString _name;			//!< Name of the product.
				QString _description;	//!< Description of the product.
				CreateFunction _create;	//!< Helper function which creates a product.

		};

	public:

		/**
		 *	Registers a new product.
		 *
		 *	@param name Name of the product.
		 *	@param description Description of the product.
		 *	@param function Helper function to create the product.
		 */

		static void registerProductMetaType(
			const QString& name,
			const QString& description,
			CreateFunction function
		) {
			Factory& _this = instance( );
			_this._registry.append( ProductMetaType( name, description, function ));
		}



		/**
		 *	Returns a set of informations about all the registered types, in
		 *	the form < name, description >.
		 *
		 *	@return Map of informations.
		 */

		static Informations informations( ) {

			Factory& _this = instance( );
			Informations informations;

			foreach ( ProductMetaType meta, _this._registry ) {
				informations.insert( meta.name( ), meta.description( ));
			}

			return informations;
		}



		/**
		 *	Creates the product which is associated with the given name.
		 *
		 *	@param name Name of the product.
		 *	@return An instance of the product, or 0 if there is no product
		 *		found with the given name.
		 */

		static Product* create( const QString& name ) {
			Factory& _this = instance( );

			foreach ( const ProductMetaType& meta, _this._registry ) {
				if ( name.compare( meta.name( )) == 0 ) {
					return meta.create( );
				}
			}

			return 0;
		}

	private:

		/**
		 *	Private constructor to prevent copy.
		 */

		Factory( ) { }



		/**
		 *	Private copy constructor to prevent copy.
		 *
		 *	@param other Other factory.
		 */

		Factory( const Factory& other ) {

			Q_UNUSED( other );
		}



		/**
		 *	Private assignment operator to prevent copy.
		 *
		 *	@param other Other factory.
		 */

		void operator=( const Factory& other ) {

			Q_UNUSED( other );
		}



		/**
		 *	Returns a unique instance of the Factory.
		 *
		 *	@return Unique instance.
		 */

		static Factory& instance( ) {

			static Factory factory;
			return factory;
		}

	private:

		QList< ProductMetaType > _registry;	//!< Regitry of products meta.

};



/**
 *	An utility class to register products for the factory.
 */

template< class Ancestor, class Product >
class ProductRegistrar {

	public:

		/**
		 *	Constructor.
		 *
		 *	@param name Name of the product.
		 *	@param description Description of the product.
		 */

		ProductRegistrar( const QString& name, const QString& description ) {

			Factory< Ancestor >::registerProductMetaType( name, description, create );
		}



		/**
		 *	Returns an instance of the product.
		 *
		 *	@return Product instance.
		 */

		static Ancestor* create( ) {

			return new Product;
		}

};



/**
 *	A macro to register products easily.
 */

#define REGISTER_PRODUCT( baseClassName, className, name, description ) \
	ProductRegistrar< baseClassName, className > className##Product( \
		QObject::tr( name ), \
		QObject::tr( description ) \
	);

#endif // FACTORY_H
