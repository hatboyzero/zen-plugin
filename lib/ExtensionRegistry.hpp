//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Zen Plugin Framework
//
// Copyright (C) 2001 - 2016 Raymond A. Richards
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#ifndef ZEN_PLUGIN_EXTENSION_REGISTRY_HPP_INCLUDED
#define ZEN_PLUGIN_EXTENSION_REGISTRY_HPP_INCLUDED

#include <Zen/Plugin/I_ExtensionRegistry.hpp>

// #include "PluginInfo.hpp"

#include <list>
#include <map>
#include <memory>
#include <string>

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
namespace Zen {
namespace Plugin {
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

class ExtensionRegistry
:   public I_ExtensionRegistry
{
    /// @name Types
    /// @{
public:
    typedef std::list<pExtensionPoint_type>                             ExtensionPointContainer_type;
    typedef std::shared_ptr<ExtensionPointContainer_type>               pExtensionPointContainer_type;
    typedef std::map<std::string, extension_point_container_ptr_type>   NamespaceContainer_type;
    /// @}

    /// @name I_ExtensionRegistry implementation
    /// @{
public:
    // virtual I_ExtensionRegistry::pExtensionQuery_type createQuery();
    // virtual pExtension_type findExtension(pExtensionQuery_type _pQuery, extension_filter_type _visitor);
    // virtual ClassFactory_ref_type getClassFactory(pExtension_type _pExtension);
  /// @}

    /// @name ExtensionRegistry implementation
    /// @{
public:
    /// Get the singleton
    static ExtensionRegistry& getSingleton() { return *(dynamic_cast<ExtensionRegistry*>(&I_ExtensionRegistry::getSingleton())); }

    /// Create an extension point
    // boost::shared_ptr<ExtensionPoint> createExtensionPoint(const I_ConfigurationElement& _config, PluginInfo& _plugin);

    /// Installs an extension point that is fully parsed and ready for use
    // void installExtensionPoint(boost::shared_ptr<ExtensionPoint> _extensionPoint);

    /// Create an extension
    // boost::shared_ptr<Extension> createExtension(const I_ConfigurationElement& _config, PluginInfo& _plugin);

    /// Installs an extension that is fully parsed and ready for use
    // void installExtension(boost::shared_ptr<Extension> _extension);

    /// @}

    /// @name 'Structors
    /// @{
public:
			 ExtensionRegistry();
	virtual ~ExtensionRegistry();
    /// @}

    /// @name Member variables
    /// @{
private:
    /// Extension point namespace map with a list of extension points as the value.
    NamespaceContainer_type         m_namespaces;

    typedef std::map<std::string, pExtension_type >   ExtensionPointMap_type;

    /// Extension point id (fully qualified including namespace) mapped to extension point objects
    ExtensionPointMap_type   m_extensionPoints;

    /// List of extensions
    /// @todo Should this be a map of some sort?
    typedef std::list<pExtension_type>  Extensions_type;    
    Extensions_type         m_extensions;
    /// @}

};	// class ExtensionRegistry

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
}   // namespace Plugin
}   // namespace Zen
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif // ZEN_PLUGIN_EXTENSION_REGISTRY_HPP_INCLUDED
