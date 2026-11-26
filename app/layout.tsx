import { Analytics } from '@vercel/analytics/next'
import type { Metadata, Viewport } from 'next'
import { Bricolage_Grotesque, Geist } from 'next/font/google'
import './globals.css'
import Script from 'next/script'

const geist = Geist({ subsets: ['latin'], variable: '--font-geist' })
const bricolage = Bricolage_Grotesque({ subsets: ['latin'], variable: '--font-bricolage' })

export const metadata: Metadata = {
  title: 'Brain Sprint — Interactive Quiz',
  description:
    'Test your knowledge across general trivia, science, history, and geography. Race the clock, build streaks, and learn something new with every answer.',
  verification: {
    google:
      "3-iCJyX6_zf2crF5ZLk9fRCscPvU14-CPxwqkN4-ihE",
  },
  generator: 'v0.app',
  icons: {
    icon: [
      {
        url: '/icon-light-32x32.png',
        media: '(prefers-color-scheme: light)',
      },
      {
        url: '/icon-dark-32x32.png',
        media: '(prefers-color-scheme: dark)',
      },
      {
        url: '/icon.svg',
        type: 'image/svg+xml',
      },
    ],
    apple: '/apple-icon.png',
  },
}

export const viewport: Viewport = {
  colorScheme: 'light',
  themeColor: '#f7f3ea',
}

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode
}>) {
  return (
    <html lang="en" className={`${geist.variable} ${bricolage.variable}`}>
      <head>
        <Script
          id="gtm-script"
          strategy="afterInteractive"
          src="https://www.googletagmanager.com/gtm.js?id=GTM-KK6JWBB3"
        />
        <Script id="gtm-init" strategy="afterInteractive">
          {`
            window.dataLayer = window.dataLayer || [];
            function gtag(){dataLayer.push(arguments);}
            gtag('js', new Date());
          `}
        </Script>
      </head>
      <body className="font-sans antialiased">
        {children}
        {process.env.NODE_ENV === 'production' && <Analytics />}
      </body>
    </html>
  )
}
