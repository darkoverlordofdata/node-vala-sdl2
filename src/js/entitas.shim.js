/**
 * Shim to import ambient modules
 */
entitas['entitas'] = entitas

define([], () => {return {
    'entitas': entitas,
    'entitas.utils': entitas.utils,
    'entitas.exceptions': entitas.exceptions
}})
