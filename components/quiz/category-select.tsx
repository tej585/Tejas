import { ArrowUpRight, FlaskConical, Globe2, Landmark, Sparkles, Timer, Zap, Keyboard } from 'lucide-react'
import type { Category } from '@/lib/quiz-data'
import { SECONDS_PER_QUESTION } from '@/lib/quiz-data'

const icons = {
  sparkles: Sparkles,
  flask: FlaskConical,
  landmark: Landmark,
  globe: Globe2,
}

type Props = {
  categories: Category[]
  onSelect: (category: Category) => void
}

export function CategorySelect({ categories, onSelect }: Props) {
  return (
    <div className="mx-auto flex w-full max-w-5xl flex-col gap-12 px-4 py-12 md:py-20">
      <header className="flex flex-col gap-6">
        <p className="inline-flex w-fit items-center gap-2 rounded-full border border-foreground/15 bg-card px-3 py-1 text-sm font-medium">
          <span className="size-2 rounded-full bg-primary" aria-hidden="true" />
          {'Brain Sprint'}
        </p>
        <h1 className="font-display text-5xl font-bold leading-[1.05] tracking-tight text-balance md:text-7xl">
          {'How much do you '}
          <span className="relative inline-block">
            <span className="relative z-10">really</span>
            <span className="absolute inset-x-0 bottom-1 z-0 h-4 -rotate-1 bg-highlight md:h-6" aria-hidden="true" />
          </span>
          {' know?'}
        </h1>
        <p className="max-w-xl text-lg leading-relaxed text-muted-foreground text-pretty">
          {'Pick a category, race the clock, and build your streak. Every answer comes with a quick fact so you learn as you play.'}
        </p>
        <ul className="flex flex-wrap gap-x-6 gap-y-2 text-sm text-muted-foreground">
          <li className="flex items-center gap-2">
            <Timer className="size-4 text-foreground" aria-hidden="true" />
            {`${SECONDS_PER_QUESTION}s per question`}
          </li>
          <li className="flex items-center gap-2">
            <Zap className="size-4 text-foreground" aria-hidden="true" />
            {'Speed bonus points'}
          </li>
          <li className="flex items-center gap-2">
            <Keyboard className="size-4 text-foreground" aria-hidden="true" />
            {'Press 1–4 to answer'}
          </li>
        </ul>
      </header>

      <section aria-labelledby="categories-heading" className="flex flex-col gap-4">
        <h2 id="categories-heading" className="text-sm font-semibold uppercase tracking-widest text-muted-foreground">
          {'Choose a category'}
        </h2>
        <div className="grid gap-4 sm:grid-cols-2">
          {categories.map((category, index) => {
            const Icon = icons[category.icon]
            return (
              <button
                key={category.id}
                type="button"
                onClick={() => onSelect(category)}
                className="group flex flex-col gap-6 rounded-2xl border-2 border-foreground bg-card p-6 text-left shadow-[4px_4px_0_0_var(--foreground)] transition-all hover:-translate-x-0.5 hover:-translate-y-0.5 hover:shadow-[6px_6px_0_0_var(--foreground)] focus-visible:outline-none focus-visible:ring-4 focus-visible:ring-ring active:translate-x-0.5 active:translate-y-0.5 active:shadow-[2px_2px_0_0_var(--foreground)]"
              >
                <div className="flex items-start justify-between">
                  <span
                    className={`flex size-12 items-center justify-center rounded-xl border-2 border-foreground ${
                      index % 2 === 0 ? 'bg-primary text-primary-foreground' : 'bg-highlight text-foreground'
                    }`}
                  >
                    <Icon className="size-6" aria-hidden="true" />
                  </span>
                  <ArrowUpRight
                    className="size-6 transition-transform group-hover:translate-x-0.5 group-hover:-translate-y-0.5"
                    aria-hidden="true"
                  />
                </div>
                <div className="flex flex-col gap-1">
                  <h3 className="font-display text-2xl font-bold">{category.name}</h3>
                  <p className="text-muted-foreground">{category.description}</p>
                </div>
                <p className="text-sm font-medium">{`${category.questions.length} questions`}</p>
              </button>
            )
          })}
        </div>
      </section>
    </div>
  )
}
