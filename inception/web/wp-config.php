<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * Localized language
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'wpuser' );

/** Database password */
define( 'DB_PASSWORD', 'password' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',          'lAG[KO@vPhDJ7yhoa.8rKnmcmM}Ds4MTCaCq%.D]1hXc%LWMEh.|3s[p@mDQYWf#' );
define( 'SECURE_AUTH_KEY',   'fI;Ej 54l_(+WI3`f!*9wtOXxk0(bEBz}Gd:`Muz[/B~F]Fa+L<(_hmDA?fY&cM=' );
define( 'LOGGED_IN_KEY',     'mI^$cgsqw]_5D$L]|Zt]BH4~rU!B^@ycpcQ1QxpLeVckn8GgKji&o(g1j]:![89L' );
define( 'NONCE_KEY',         '3x)490w})du`^3Kk2D+glJKRRYO~?fSmV%(}C|w}QmgTs2M1Z0kY8Go)<M3b6=@{' );
define( 'AUTH_SALT',         'fX/,{:GS#G$b%,v=:Y}kS2=;?H#c+kI)}*spWHlbq9[xw<>|R~-M!*BN5Ex~kj05' );
define( 'SECURE_AUTH_SALT',  'Log~P{X64?>`8GHkO`LUZK6[`wP[aqK(f)oAe0o-cIP g2s^INoe~:ZJbF*T,RO}' );
define( 'LOGGED_IN_SALT',    '%~.Qn?j;Q56p(l?CNAb?v[+wE}mU=zFiBO**`dLzx:0xsyIFpC,=E0,#i9OM7ip_' );
define( 'NONCE_SALT',        '1gdMXM(%>1VukK$g9A:)rJ8xiTsrSAb(nA(x62WW7ZJ!wX</2~{;GIH~SJWAt*x=' );
define( 'WP_CACHE_KEY_SALT', ']F<,W KKP)-Y@rc]eNXA~R +A>3&maoLc)d?1.$_@5PPZADob=IMnn?|Jd/,[Cv<' );


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';


/* Add any custom values between this line and the "stop editing" line. */



/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
if ( ! defined( 'WP_DEBUG' ) ) {
	define( 'WP_DEBUG', false );
}

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
